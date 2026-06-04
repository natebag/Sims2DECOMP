#!/bin/bash
# diff_func.sh — side-by-side disassembly diff for a single matched function.
#
# Compiles the C++ source with SN ProDG (via verify_match.sh), then objdumps
# both the DOL bytes and the compiled bytes and prints them in two columns
# with mismatch highlighting. The poor man's objdiff for projects without the
# full ninja target/base build pipeline.
#
# Usage:
#   bash tools/diff_func.sh [--strict] [--symbol NAME] <match_file.cpp> <addr> <size>
#
# Example:
#   bash tools/diff_func.sh src/wip/match_0x801056EC_cXObjectImpl__KillSelf.cpp 0x801056EC 148

set -e

VERIFY_ARGS=()
POSITIONAL=()
while [ $# -gt 0 ]; do
    case "$1" in
        --strict)
            VERIFY_ARGS+=(--strict)
            shift
            ;;
        --symbol)
            if [ -z "${2:-}" ]; then
                echo "ERROR: --symbol requires a symbol name argument" >&2
                exit 1
            fi
            VERIFY_ARGS+=(--symbol "$2")
            shift 2
            ;;
        --symbol=*)
            VERIFY_ARGS+=(--symbol "${1#--symbol=}")
            shift
            ;;
        --)
            shift
            while [ $# -gt 0 ]; do POSITIONAL+=("$1"); shift; done
            ;;
        *)
            POSITIONAL+=("$1")
            shift
            ;;
    esac
done

if [ ${#POSITIONAL[@]} -lt 3 ]; then
    echo "Usage: $0 [--strict] [--symbol NAME] <match_file.cpp> <addr> <size>" >&2
    exit 1
fi

FILE="${POSITIONAL[0]}"
ADDR="${POSITIONAL[1]}"
SIZE="${POSITIONAL[2]}"

if [ ! -f "$FILE" ]; then
    echo "ERROR: $FILE not found" >&2
    exit 1
fi

# Run verify_match.sh to compile + extract DOL bytes. Don't propagate its
# non-zero exit on MISMATCH — that's the whole reason we're being run.
VERIFY_OUT=$(bash tools/verify_match.sh "${VERIFY_ARGS[@]}" "$FILE" "$ADDR" "$SIZE" 2>&1 || true)

# Pull hex blobs from verify_match output (one-line hex strings)
DOL_HEX=$(echo "$VERIFY_OUT" | grep '^DOL bytes:' | awk '{print $3}')
COMPILED_HEX=$(echo "$VERIFY_OUT" | grep '^Compiled bytes:' | awk '{print $3}')

if [ -z "$DOL_HEX" ] || [ -z "$COMPILED_HEX" ]; then
    echo "ERROR: verify_match.sh did not produce DOL+Compiled hex output." >&2
    echo "Full verify output (last 20 lines):" >&2
    echo "$VERIFY_OUT" | tail -20 >&2
    exit 1
fi

# Pick a PowerPC objdump binary. Mirrors the search verify_match.sh does
# (devkitPPC under DEVKITPPC env var, common Windows install paths, then PATH).
OBJDUMP=""
for cand in \
    "${DEVKITPPC:-}/bin/powerpc-eabi-objdump" \
    "${DEVKITPPC:-}/bin/powerpc-eabi-objdump.exe" \
    "/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe" \
    "/mnt/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe" \
    "/opt/devkitpro/devkitPPC/bin/powerpc-eabi-objdump" \
    "/c/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe" \
    "/d/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"; do
    if [ -n "$cand" ] && [ -x "$cand" ]; then OBJDUMP="$cand"; break; fi
done
if [ -z "$OBJDUMP" ]; then
    for cand in powerpc-eabi-objdump powerpc-linux-gnu-objdump ppc-eabi-objdump; do
        if command -v "$cand" >/dev/null 2>&1; then OBJDUMP="$cand"; break; fi
    done
fi
if [ -z "$OBJDUMP" ]; then
    echo "ERROR: powerpc-eabi-objdump not found." >&2
    echo "Set DEVKITPPC env var or install devkitPPC." >&2
    exit 1
fi
PYTHON="$(command -v python3 || command -v python)"
if [ -z "$PYTHON" ]; then
    echo "ERROR: Python interpreter not found." >&2
    exit 1
fi

TMP_ROOT="build/tmp"
mkdir -p "$TMP_ROOT"
TMPDIR=$(mktemp -d "$TMP_ROOT/diff_func.XXXXXX")
trap "rm -rf $TMPDIR" EXIT

# Helper: hex string -> raw binary -> objdump disasm (one instruction per line)
disasm() {
    local hex="$1"
    local out="$2"
    local raw="$TMPDIR/raw.bin"
    local objdump_input
    # Convert hex string to raw bytes
    "$PYTHON" -c "import sys; sys.stdout.buffer.write(bytes.fromhex('$hex'))" > "$raw"
    objdump_input="$raw"
    if [[ "$OBJDUMP" == *.exe ]] && command -v wslpath >/dev/null 2>&1; then
        objdump_input=$(wslpath -w "$raw")
    fi
    # Disasm; with --no-addresses each instruction line starts with a TAB
    # followed by the mnemonic. Section/header chatter has no leading tab.
    "$OBJDUMP" -D -b binary -m powerpc -EB --no-show-raw-insn --no-addresses "$objdump_input" \
        2>/dev/null | awk '/^\t/ {sub(/^\t/, "", $0); sub(/\r$/, "", $0); print}' > "$out"
}

disasm "$DOL_HEX" "$TMPDIR/dol.s"
disasm "$COMPILED_HEX" "$TMPDIR/compiled.s"

# Side-by-side with mismatch highlighting
RED=$'\033[0;31m'
GREEN=$'\033[0;32m'
NC=$'\033[0m'

VERDICT="UNKNOWN"
if echo "$VERIFY_OUT" | grep -q '^MATCH!'; then
    VERDICT="${GREEN}MATCH${NC}"
elif echo "$VERIFY_OUT" | grep -qE 'MISMATCH|SIZE_MISMATCH'; then
    VERDICT="${RED}MISMATCH${NC}"
fi

echo
printf "  Function:  %s\n" "$FILE"
printf "  Address:   %s   Size: %sB\n" "$ADDR" "$SIZE"
printf "  Verdict:   %b\n" "$VERDICT"
printf "  Objdump:   %s\n" "$OBJDUMP"
if [ ${#VERIFY_ARGS[@]} -gt 0 ]; then
    printf "  Verify:    %s\n" "${VERIFY_ARGS[*]}"
fi
echo
printf "  %-8s  %-50s  | %s\n" "Offset" "DOL (original)" "Compiled (your C++)"
printf "  %-8s--%-50s--+--%s\n" "$(printf '%.0s-' {1..8})" "$(printf '%.0s-' {1..50})" "$(printf '%.0s-' {1..50})"

idx=0
paste -d'|' "$TMPDIR/dol.s" "$TMPDIR/compiled.s" | while IFS='|' read -r left right; do
    left=$(echo "$left" | sed 's/^\s\+//')
    right=$(echo "$right" | sed 's/^\s\+//')
    off=$(printf "0x%04X" $((idx * 4)))
    if [ "$left" = "$right" ]; then
        printf "  %-8s  %-50s  | %s\n" "$off" "$left" "$right"
    else
        printf "  %-8s  ${RED}%-50s${NC}  | ${RED}%s${NC}\n" "$off" "$left" "$right"
    fi
    idx=$((idx + 1))
done

echo
