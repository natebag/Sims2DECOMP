#!/bin/bash
# git_safe_commit.sh — wrap `git commit` with stale-lock detection and retry.
#
# Fleet-contention symptom: 3+ workers committing concurrently on Windows
# leave orphaned .git/index.lock files when a git process crashes mid-write,
# blocking every subsequent commit until the lock is cleared manually.
# This wrapper handles the detection and recovery so workers don't need to.
#
# Usage: tools/git_safe_commit.sh [same args as git commit]
#
# Behavior:
#   1. Pre-check .git/index.lock
#      - absent                 -> proceed
#      - < 30s old               -> poll 2s x up to 60s, then proceed
#      - > 30s old + git procs   -> poll 5s x up to 60s, then proceed
#      - > 30s old + no procs    -> declare stale, remove, proceed
#   2. Invoke `git commit "$@"`
#   3. If exit=128 and stderr mentions index.lock: sleep 5, retry once
#   4. Pass through exit code

set -u

LOCK=".git/index.lock"
MAX_WAIT=60
POLL_FRESH=2
POLL_BUSY=5
STALE_AGE=30

log() { echo "[git_safe_commit] $*" >&2; }

# Cross-platform: epoch mtime of a file ("" if missing)
lock_age_secs() {
    if [ ! -e "$LOCK" ]; then echo ""; return; fi
    local now mtime
    now=$(date +%s)
    # stat -c on GNU (Linux/Git-Bash/MSYS), stat -f on BSD/Mac
    if stat -c %Y "$LOCK" >/dev/null 2>&1; then
        mtime=$(stat -c %Y "$LOCK")
    else
        mtime=$(stat -f %m "$LOCK")
    fi
    echo $((now - mtime))
}

# Count running git processes (exclude this wrapper's children)
git_proc_count() {
    local uname_s
    uname_s=$(uname -s 2>/dev/null || echo "")
    case "$uname_s" in
        MINGW*|MSYS*|CYGWIN*|"")
            # Windows: tasklist. Subtract 1 for the header line when there's output.
            local out
            out=$(tasklist //FI "IMAGENAME eq git.exe" 2>/dev/null | grep -c "git.exe" || true)
            echo "${out:-0}"
            ;;
        *)
            pgrep -c '^git$' 2>/dev/null || echo 0
            ;;
    esac
}

wait_for_lock_clear() {
    local waited=0 age poll
    while true; do
        age=$(lock_age_secs)
        if [ -z "$age" ]; then
            return 0
        fi
        if [ "$waited" -ge "$MAX_WAIT" ]; then
            return 1
        fi
        if [ "$age" -lt "$STALE_AGE" ]; then
            poll="$POLL_FRESH"
            log "lock present (age=${age}s, fresh) — waited ${waited}s, polling in ${poll}s"
        else
            local procs
            procs=$(git_proc_count)
            if [ "${procs:-0}" -eq 0 ]; then
                log "STALE LOCK DETECTED (age=${age}s, no git procs) — removing"
                if rm "$LOCK" 2>/dev/null; then
                    return 0
                else
                    log "ERROR: failed to remove stale lock: $LOCK"
                    return 2
                fi
            fi
            poll="$POLL_BUSY"
            log "lock present (age=${age}s, ${procs} git procs running) — waited ${waited}s, polling in ${poll}s"
        fi
        sleep "$poll"
        waited=$((waited + poll))
    done
}

# SAFETY: do not touch .git/index (the real index), only .git/index.lock.
[ "$LOCK" = ".git/index.lock" ] || { log "LOCK path misconfigured"; exit 2; }

# 1. Pre-check
if [ -e "$LOCK" ]; then
    wait_for_lock_clear || {
        log "ERROR: lock never cleared after ${MAX_WAIT}s, giving up"
        exit 2
    }
fi

# 2. Invoke git commit, capture stderr
tmpfile=$(mktemp 2>/dev/null || echo "/tmp/git_safe_commit.$$")
trap 'rm -f "$tmpfile"' EXIT

git commit "$@" 2> >(tee "$tmpfile" >&2)
rc=$?

# 3. Retry once on lock-race exit
if [ "$rc" -eq 128 ] && grep -q "index.lock" "$tmpfile" 2>/dev/null; then
    log "commit hit index.lock race (exit 128) — retrying once in 5s"
    sleep 5
    wait_for_lock_clear || true
    git commit "$@"
    rc=$?
fi

exit "$rc"
