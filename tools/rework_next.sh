#!/bin/bash
# rework_next.sh — dedup helper for the fake_matches rework queue.
#
# Shard manifests go stale fast during a bulk rework run — workers keep
# picking files that another worker already cracked and moved to
# src/matched/. KimiWorker's last batch was 0/14 net because all 14 were
# duplicates against committed work that postdated their manifest.
#
# This helper re-checks live git state on every invocation and emits
# target files whose addresses are NOT already committed under
# src/matched/, so workers can safely queue up new work.
#
# Usage:
#   bash tools/rework_next.sh [--count N] [--pattern TYPE]
#                             [--min-size N] [--max-size N]
#
# Options:
#   --count N       how many candidates to emit (default 10)
#   --pattern TYPE  filter by inferred ctor shape:
#                     vtable  — vtable-only leaf ctor (lis/addi/stw 0)
#                     zero    — multi-field pure zero-init ctor
#                     param   — stores incoming args into this->fields
#                     complex — loads, branches, SDA, bl calls
#   --min-size N    only candidates >= N bytes
#   --max-size N    only candidates <= N bytes
#
# Output: one absolute path per line, sorted by size ascending (smallest
# first) so warm-up crackers get trivial targets and experienced workers
# can --max-size filter for harder ones.
#
# Correctness note: a file is a candidate if ANY of its // 0xADDR headers
# is NOT yet committed under src/matched/. Multi-function fake files that
# had some functions split out individually are still candidates if there
# are unfinished functions remaining.

set -u

COUNT=10
PATTERN=""
MIN_SIZE=0
MAX_SIZE=999999
FAKE_DIR="src/wip/fake_matches"
MATCHED_DIR="src/matched"

log() { echo "[rework_next] $*" >&2; }

# --- arg parsing --- #
while [ $# -gt 0 ]; do
    case "$1" in
        --count)    shift; COUNT="$1"; shift ;;
        --count=*)  COUNT="${1#--count=}"; shift ;;
        --pattern)  shift; PATTERN="$1"; shift ;;
        --pattern=*) PATTERN="${1#--pattern=}"; shift ;;
        --min-size)   shift; MIN_SIZE="$1"; shift ;;
        --min-size=*) MIN_SIZE="${1#--min-size=}"; shift ;;
        --max-size)   shift; MAX_SIZE="$1"; shift ;;
        --max-size=*) MAX_SIZE="${1#--max-size=}"; shift ;;
        -h|--help)
            sed -n '2,27p' "$0" | sed 's/^# \{0,1\}//'
            exit 0
            ;;
        *)
            log "ERROR: unknown arg: $1"
            exit 2
            ;;
    esac
done

case "$PATTERN" in
    ""|vtable|zero|param|complex) ;;
    *)
        log "ERROR: invalid --pattern: $PATTERN (allowed: vtable zero param complex)"
        exit 2
        ;;
esac

if [ ! -d "$FAKE_DIR" ]; then
    log "ERROR: $FAKE_DIR does not exist"
    exit 2
fi

# --- Step 1: build a lowercase-address index from git ls-files src/matched/ --- #
# A file is "already matched" if its committed path contains the 8-char hex
# address (case-insensitive). We build a bash associative array for O(1)
# lookup — grepping a string variable once per address is O(nm) and is
# orders of magnitude slower on 169 fake files * 7800 committed addresses.
declare -A MATCHED_SET
matched_count=0
while IFS= read -r addr; do
    [ -z "$addr" ] && continue
    MATCHED_SET["$addr"]=1
    matched_count=$((matched_count + 1))
done < <(git ls-files "$MATCHED_DIR" 2>/dev/null \
            | grep -oEi '[0-9a-f]{8}' \
            | tr 'A-F' 'a-f' \
            | sort -u)

# Sanity: refuse to run if we got zero matched addrs — probably wrong cwd.
if [ "$matched_count" -lt 100 ]; then
    log "WARNING: only $matched_count matched addresses found in $MATCHED_DIR — are you in the repo root?"
fi

# --- Step 2: walk fake_matches, extract addrs, classify, filter --- #
# Output format to the pipeline stage:
#   SIZE<TAB>PATTERN<TAB>PATH
# so we can sort+filter downstream.

classify_file() {
    # Classify a fake_matches .cpp into one of: vtable zero param complex.
    # Uses a single grep invocation per category (no echo/pipe subshells).
    local f="$1"
    # complex: has conditional/branch/load-bytes/float/call
    if grep -qE '"(bl|lbz|lhz|beqlr|cmpw|lfs|bge|blt|andi\.)' "$f" 2>/dev/null; then
        echo "complex"
        return
    fi
    # param: stores from parameter registers r4-r9
    if grep -qE '"stw[[:space:]]+[4-9],' "$f" 2>/dev/null; then
        echo "param"
        return
    fi
    # zero: multiple stw r0 (pure zero-init fields)
    local stw_zero_count
    stw_zero_count=$(grep -oE '"stw[[:space:]]+0,' "$f" 2>/dev/null | wc -l)
    if [ "${stw_zero_count:-0}" -ge 3 ]; then
        echo "zero"
        return
    fi
    echo "vtable"
}

process_file() {
    local f="$1"
    local any_missing=0 total_size=0 line a s

    # Header comments look like: "// 0xADDR (Nb)" or "// 0xADDR Class::Fn (Nb)".
    # Extract all in one grep, parse in-process with bash regex (no subprocess per field).
    while IFS= read -r line; do
        [ -z "$line" ] && continue
        if [[ "$line" =~ 0x([0-9A-Fa-f]{8}) ]]; then
            a="${BASH_REMATCH[1],,}"
        else
            continue
        fi
        if [[ "$line" =~ \(([0-9]+) ]]; then
            s="${BASH_REMATCH[1]}"
        else
            s=0
        fi
        if [ -z "${MATCHED_SET[$a]:-}" ]; then
            any_missing=1
        fi
        total_size=$((total_size + s))
    done < <(grep -oE '// 0x[0-9A-Fa-f]{8}[^(]*\([0-9]+[^)]*\)' "$f" 2>/dev/null)

    if [ "$total_size" -eq 0 ]; then
        log "SKIP $(basename "$f"): no parseable // 0xADDR (Nb) header"
        return 1
    fi

    if [ "$any_missing" -eq 0 ]; then
        return 1   # every addr already in matched → fully done
    fi

    if [ "$total_size" -lt "$MIN_SIZE" ] || [ "$total_size" -gt "$MAX_SIZE" ]; then
        return 1
    fi

    local pat
    pat=$(classify_file "$f")

    if [ -n "$PATTERN" ] && [ "$pat" != "$PATTERN" ]; then
        return 1
    fi

    printf '%d\t%s\t%s\n' "$total_size" "$pat" "$f"
    return 0
}

# --- Step 3: first pass — count truly-untouched files ignoring all filters.
# This gives an honest "pool size" independent of --pattern / --min-size /
# --max-size so workers can see the real remaining work count even when
# filtering. Runs the same loop but with filters temporarily suppressed.
tmpfile=$(mktemp 2>/dev/null || echo "/tmp/rework_next.$$")
trap 'rm -f "$tmpfile"' EXIT

# Save filters, apply wide-open filters for the pool count
_save_pattern="$PATTERN"
_save_min="$MIN_SIZE"
_save_max="$MAX_SIZE"
PATTERN=""
MIN_SIZE=0
MAX_SIZE=999999

total_fakes=0
total_untouched=0
for f in "$FAKE_DIR"/*.cpp; do
    [ -e "$f" ] || continue
    total_fakes=$((total_fakes + 1))
    if process_file "$f" >> "$tmpfile"; then
        total_untouched=$((total_untouched + 1))
    fi
done

# Step 4: re-apply filters against the unfiltered candidate list.
# Since process_file already writes "size<TAB>pattern<TAB>path", we can
# filter and sort the tmpfile in one awk/sort pipe.
PATTERN="$_save_pattern"
MIN_SIZE="$_save_min"
MAX_SIZE="$_save_max"

repo_root=$(git rev-parse --show-toplevel 2>/dev/null || pwd)

filtered_count=0
awk -F'\t' -v pat="$PATTERN" -v mn="$MIN_SIZE" -v mx="$MAX_SIZE" '
    {
        if ($1 < mn || $1 > mx) next
        if (pat != "" && $2 != pat) next
        print
    }
' "$tmpfile" | sort -n | head -n "$COUNT" | while IFS=$'\t' read -r sz pat_ path; do
    printf '%s\n' "$repo_root/$path"
done

# Also count the filtered result for the log
if [ -n "$PATTERN" ] || [ "$MIN_SIZE" -gt 0 ] || [ "$MAX_SIZE" -lt 999999 ]; then
    filtered_count=$(awk -F'\t' -v pat="$PATTERN" -v mn="$MIN_SIZE" -v mx="$MAX_SIZE" '
        {
            if ($1 < mn || $1 > mx) next
            if (pat != "" && $2 != pat) next
            print
        }' "$tmpfile" | wc -l)
    log "pool: $total_fakes fake_matches files, $total_untouched truly untouched (dedup vs $matched_count committed addrs); $filtered_count match current filter"
else
    log "pool: $total_fakes fake_matches files, $total_untouched truly untouched (dedup vs $matched_count committed addrs under $MATCHED_DIR)"
fi
