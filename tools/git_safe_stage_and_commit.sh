#!/bin/bash
# git_safe_stage_and_commit.sh — atomic stage + commit under fleet contention.
#
# Fleet-race symptom: worker A does `git add foo.cpp`, worker B does
# `git commit -m "msg"` (without path args) during A's wait window, and
# B's commit scoops up A's staged foo.cpp into B's commit. Happened to
# SonnetWorker2's tools/git_safe_*.sh changes, which rode along with
# SonnetWorker's match(bulk) commit 22c83e7b.
#
# Fix: use `git commit --only -m "<msg>" -- <paths>` which creates a
# temporary index inside git, applies ONLY the requested paths from the
# working index, and commits that — ignoring any other staged files from
# concurrent workers.
#
# Usage:
#   tools/git_safe_stage_and_commit.sh -m "<message>" <path1> [path2] [...]
#
# HEREDOC form for multi-line messages:
#   tools/git_safe_stage_and_commit.sh -m "$(cat <<'EOF'
#   subject line
#
#   body paragraph
#   EOF
#   )" path1 path2 path3
#
# Handles additions, modifications, AND deletions via `git add -A -- <paths>`.
# Delegates the actual commit to tools/git_safe_commit.sh so the lock-wait,
# steady-state stuck detection, and retry logic are inherited automatically.

set -u

# Resolve the absolute path to sibling git_safe_commit.sh so this wrapper
# works from any cwd (the repo root, a worktree, a subdirectory, or an
# unrelated directory where a worker happens to be staging files).
SELF_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GIT_SAFE_COMMIT="$SELF_DIR/git_safe_commit.sh"

log() { echo "[git_safe_stage_and_commit] $*" >&2; }

# --- arg parsing --- #
MSG=""
PATHS=()
while [ $# -gt 0 ]; do
    case "$1" in
        -m)
            shift
            if [ $# -eq 0 ]; then
                log "ERROR: -m requires a message argument"
                exit 2
            fi
            MSG="$1"
            shift
            ;;
        -m*)
            # -m"message" or -mmessage form
            MSG="${1#-m}"
            shift
            ;;
        --)
            shift
            while [ $# -gt 0 ]; do
                PATHS+=("$1")
                shift
            done
            ;;
        -*)
            log "ERROR: unknown flag: $1 (only -m and -- are supported)"
            exit 2
            ;;
        *)
            PATHS+=("$1")
            shift
            ;;
    esac
done

if [ -z "$MSG" ]; then
    log "ERROR: no commit message given (use -m \"...\")"
    exit 2
fi
if [ "${#PATHS[@]}" -eq 0 ]; then
    log "ERROR: no paths given"
    log "Usage: $0 -m <message> <path1> [path2] ..."
    exit 2
fi

# --- local lock-wait helper (mirrors git_safe_commit.sh) --- #
LOCK=".git/index.lock"
MAX_WAIT=120
POLL_FRESH=2
POLL_BUSY=5
STALE_AGE=30
STEADY_THRESHOLD=30

lock_age_secs() {
    if [ ! -e "$LOCK" ]; then echo ""; return; fi
    local now mtime
    now=$(date +%s)
    if stat -c %Y "$LOCK" >/dev/null 2>&1; then
        mtime=$(stat -c %Y "$LOCK")
    else
        mtime=$(stat -f %m "$LOCK")
    fi
    echo $((now - mtime))
}
lock_mtime_raw() {
    if [ ! -e "$LOCK" ]; then echo ""; return; fi
    if stat -c %Y "$LOCK" >/dev/null 2>&1; then
        stat -c %Y "$LOCK"
    else
        stat -f %m "$LOCK"
    fi
}
git_proc_count() {
    local uname_s
    uname_s=$(uname -s 2>/dev/null || echo "")
    case "$uname_s" in
        MINGW*|MSYS*|CYGWIN*|"")
            local out
            out=$(tasklist //FI "IMAGENAME eq git.exe" 2>/dev/null | grep -c "git.exe" || true)
            echo "${out:-0}"
            ;;
        *)
            pgrep -c '^git$' 2>/dev/null || echo 0
            ;;
    esac
}

wait_for_index_clear() {
    local waited=0 age procs mtime cycle=0 poll
    local steady_secs=0
    local baseline_mtime=""
    while true; do
        cycle=$((cycle + 1))
        age=$(lock_age_secs)
        if [ -z "$age" ]; then return 0; fi
        if [ "$waited" -ge "$MAX_WAIT" ]; then return 1; fi
        procs=$(git_proc_count)
        mtime=$(lock_mtime_raw)
        if [ "$age" -lt "$STALE_AGE" ]; then
            poll="$POLL_FRESH"
            log "stage wait cycle $cycle: lock age=${age}s, procs=${procs} (fresh) — waited ${waited}s"
            steady_secs=0
            baseline_mtime=""
        else
            if [ "${procs:-0}" -eq 0 ]; then
                log "STALE LOCK DETECTED (age=${age}s, no git procs) — removing"
                rm "$LOCK" 2>/dev/null || { log "ERROR: failed to remove stale lock"; return 2; }
                return 0
            fi
            if [ -z "$baseline_mtime" ]; then
                baseline_mtime="$mtime"
                steady_secs=0
            elif [ "$mtime" = "$baseline_mtime" ]; then
                steady_secs=$((steady_secs + POLL_BUSY))
            else
                baseline_mtime="$mtime"
                steady_secs=0
            fi
            if [ "$steady_secs" -ge "$STEADY_THRESHOLD" ]; then
                log "STEADY-STATE TIMEOUT (${steady_secs}s) — removing stuck lock (age=${age}s, procs=${procs})"
                rm "$LOCK" 2>/dev/null || { log "ERROR: failed to remove stuck lock"; return 2; }
                return 0
            fi
            poll="$POLL_BUSY"
            log "stage wait cycle $cycle: lock age=${age}s, procs=${procs} (steady=${steady_secs}s) — waited ${waited}s"
        fi
        sleep "$poll"
        waited=$((waited + poll))
    done
}

# --- main --- #

# Step 1: wait for any in-progress index operation to clear.
if [ -e "$LOCK" ]; then
    wait_for_index_clear || {
        log "ERROR: index.lock never cleared, giving up"
        exit 2
    }
fi

# Step 2: stage only the requested paths into the working index.
# Using `git add -A -- <paths>` handles additions, modifications, AND
# deletions uniformly. Retry once if the index.lock races us.
log "staging ${#PATHS[@]} path(s) via git add -A"
if ! git add -A -- "${PATHS[@]}" 2>&1; then
    log "git add failed — retrying after lock clear"
    wait_for_index_clear || { log "ERROR: index.lock stuck during retry"; exit 2; }
    git add -A -- "${PATHS[@]}" || { log "ERROR: git add failed twice"; exit 2; }
fi

# Step 3: delegate the commit to git_safe_commit.sh with --only.
# --only tells git to build a temporary index from HEAD, overlay ONLY
# the working-index entries for the specified paths, and commit that.
# Any other files concurrently staged by other workers are ignored.
log "committing via git_safe_commit.sh --only"
exec bash "$GIT_SAFE_COMMIT" --only -m "$MSG" -- "${PATHS[@]}"
