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
#      - absent                    -> proceed
#      - < 30s old                  -> poll 2s x up to 120s, then proceed
#      - > 30s old + no git procs   -> declare stale, remove, proceed
#      - > 30s old + cycling procs  -> poll 5s, keep waiting (real contention)
#      - > 30s old + STEADY procs   -> after 30s of steady-state (proc count
#                                      ± 1 AND lock mtime unchanged), declare
#                                      stuck, remove, and retry
#   2. Invoke `git commit "$@"`
#   3. If exit=128 and stderr mentions index.lock: sleep 5, retry once
#   4. Pass through exit code

set -u

LOCK=".git/index.lock"
MAX_WAIT=120
POLL_FRESH=2
POLL_BUSY=5
STALE_AGE=30
STEADY_THRESHOLD=30   # seconds of steady state before force-removing a stuck lock

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

# Raw mtime (epoch seconds) — used to detect whether the lock file is
# being actively rewritten by cycling git processes. Empty if missing.
lock_mtime() {
    if [ ! -e "$LOCK" ]; then echo ""; return; fi
    if stat -c %Y "$LOCK" >/dev/null 2>&1; then
        stat -c %Y "$LOCK"
    else
        stat -f %m "$LOCK"
    fi
}

# Count running git processes
git_proc_count() {
    local uname_s
    uname_s=$(uname -s 2>/dev/null || echo "")
    case "$uname_s" in
        MINGW*|MSYS*|CYGWIN*|"")
            # Windows: tasklist. Count lines that contain "git.exe".
            local out
            out=$(tasklist //FI "IMAGENAME eq git.exe" 2>/dev/null | grep -c "git.exe" || true)
            echo "${out:-0}"
            ;;
        *)
            pgrep -c '^git$' 2>/dev/null || echo 0
            ;;
    esac
}

# Return |a - b|
_abs_diff() {
    local d=$(( $1 - $2 ))
    [ "$d" -lt 0 ] && d=$(( -d ))
    echo "$d"
}

wait_for_lock_clear() {
    # Steady-state detection:
    #   Primary signal is LOCK MTIME STABILITY. A lock being actively held
    #   by a real in-progress git operation has its mtime updated as git
    #   writes the new index. If the mtime stops changing for STEADY_THRESHOLD
    #   seconds — even with cycling git procs from unrelated fleet activity —
    #   the lock is stuck and must be removed.
    #
    #   Proc count is used only for the "definitive no-procs" fast-path.
    local waited=0 age poll procs mtime cycle=0
    local steady_secs=0
    local baseline_mtime=""
    local baseline_procs="-"

    while true; do
        cycle=$((cycle + 1))
        age=$(lock_age_secs)
        if [ -z "$age" ]; then
            return 0
        fi
        if [ "$waited" -ge "$MAX_WAIT" ]; then
            return 1
        fi

        procs=$(git_proc_count)
        mtime=$(lock_mtime)

        if [ "$age" -lt "$STALE_AGE" ]; then
            # Fresh lock — poll fast, don't start steady-state tracking yet.
            poll="$POLL_FRESH"
            log "wait cycle $cycle: lock age=${age}s, git procs=${procs} (fresh, no steady-state yet) — waited ${waited}s"
            steady_secs=0
            baseline_mtime=""
            baseline_procs="-"
        else
            # Stale-age threshold crossed.
            # Fast path: nobody running git → unambiguously stale.
            if [ "${procs:-0}" -eq 0 ]; then
                log "STALE LOCK DETECTED (age=${age}s, no git procs) — removing"
                if rm "$LOCK" 2>/dev/null; then
                    return 0
                else
                    log "ERROR: failed to remove stale lock: $LOCK"
                    return 2
                fi
            fi

            # Git procs ARE running. Key decision: is the lock file being
            # actively updated, or is it stuck?
            if [ -z "$baseline_mtime" ]; then
                baseline_mtime="$mtime"
                baseline_procs="$procs"
                steady_secs=0
            elif [ "$mtime" = "$baseline_mtime" ]; then
                # Lock mtime unchanged since last cycle — the cycling procs
                # (if any) are not making progress on this lock. Count the
                # cycle towards the steady timer.
                steady_secs=$((steady_secs + POLL_BUSY))
            else
                # Lock mtime changed — a git proc actually updated it.
                # Someone is making progress. Reset the timer and re-baseline.
                baseline_mtime="$mtime"
                baseline_procs="$procs"
                steady_secs=0
            fi

            if [ "$steady_secs" -ge "$STEADY_THRESHOLD" ]; then
                log "STEADY-STATE TIMEOUT (${steady_secs}s unchanged mtime) — removing stuck lock (age=${age}s, procs=${procs})"
                if rm "$LOCK" 2>/dev/null; then
                    return 0
                else
                    log "ERROR: failed to remove stuck lock: $LOCK"
                    return 2
                fi
            fi

            poll="$POLL_BUSY"
            log "wait cycle $cycle: lock age=${age}s, git procs=${procs} (steady=${steady_secs}s, baseline_procs=${baseline_procs}) — waited ${waited}s"
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
