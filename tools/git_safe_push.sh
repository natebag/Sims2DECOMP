#!/bin/bash
# git_safe_push.sh — wrap `git push` with stale-lock detection and retry.
#
# Push doesn't touch .git/index.lock, but it does acquire per-ref locks
# under .git/refs/remotes/<remote>/<branch>.lock when updating tracking refs.
# Fleet contention can leave those orphaned too. Same retry pattern as
# git_safe_commit.sh, adapted to per-ref locks.
#
# Usage: tools/git_safe_push.sh [same args as git push]
#
# Behavior mirrors git_safe_commit.sh:
#   - < 30s lock age -> poll 2s
#   - > 30s + no procs -> stale, remove
#   - > 30s + cycling procs -> keep waiting
#   - > 30s + STEADY procs for 30s -> stuck, force-remove
#   - Total timeout 120s

set -u

MAX_WAIT=120
POLL_FRESH=2
POLL_BUSY=5
STALE_AGE=30
STEADY_THRESHOLD=30

log() { echo "[git_safe_push] $*" >&2; }

find_ref_locks() {
    find .git/refs -name '*.lock' 2>/dev/null
    [ -f .git/packed-refs.lock ] && echo ".git/packed-refs.lock"
    [ -f .git/HEAD.lock ] && echo ".git/HEAD.lock"
}

lock_age_secs() {
    local f="$1"
    [ -e "$f" ] || { echo ""; return; }
    local now mtime
    now=$(date +%s)
    if stat -c %Y "$f" >/dev/null 2>&1; then
        mtime=$(stat -c %Y "$f")
    else
        mtime=$(stat -f %m "$f")
    fi
    echo $((now - mtime))
}

lock_mtime_raw() {
    local f="$1"
    [ -e "$f" ] || { echo ""; return; }
    if stat -c %Y "$f" >/dev/null 2>&1; then
        stat -c %Y "$f"
    else
        stat -f %m "$f"
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

_abs_diff() {
    local d=$(( $1 - $2 ))
    [ "$d" -lt 0 ] && d=$(( -d ))
    echo "$d"
}

wait_for_refs_clear() {
    # Same steady-state detection as git_safe_commit.sh: track whether the
    # oldest stale ref lock's mtime has been unchanged for STEADY_THRESHOLD
    # seconds. If so, even with cycling git procs, the lock is stuck and is
    # force-removed.
    local waited=0 locks age poll oldest_stale procs mtime cycle=0
    local steady_secs=0
    local baseline_mtime=""
    local baseline_procs="-"

    while true; do
        cycle=$((cycle + 1))
        locks=$(find_ref_locks)
        if [ -z "$locks" ]; then return 0; fi
        if [ "$waited" -ge "$MAX_WAIT" ]; then return 1; fi

        oldest_stale=""
        local any_fresh=0 oldest_age=0 oldest_mtime=""
        while IFS= read -r f; do
            [ -z "$f" ] && continue
            age=$(lock_age_secs "$f")
            [ -z "$age" ] && continue
            if [ "$age" -lt "$STALE_AGE" ]; then
                any_fresh=1
            else
                oldest_stale="$f"
                oldest_age="$age"
                oldest_mtime=$(lock_mtime_raw "$f")
            fi
        done <<< "$locks"

        procs=$(git_proc_count)

        if [ "$any_fresh" -eq 1 ]; then
            poll="$POLL_FRESH"
            log "wait cycle $cycle: ref lock(s) present (fresh), git procs=${procs} — waited ${waited}s"
            steady_secs=0
            baseline_mtime=""
            baseline_procs="-"
        else
            if [ "${procs:-0}" -eq 0 ] && [ -n "$oldest_stale" ]; then
                log "STALE REF LOCK DETECTED ($oldest_stale, age=${oldest_age}s, no git procs) — removing"
                if rm "$oldest_stale" 2>/dev/null; then
                    continue
                else
                    log "ERROR: failed to remove stale ref lock: $oldest_stale"
                    return 2
                fi
            fi

            # Procs running — track whether the lock mtime is stuck.
            if [ -z "$baseline_mtime" ]; then
                baseline_mtime="$oldest_mtime"
                baseline_procs="$procs"
                steady_secs=0
            elif [ "$oldest_mtime" = "$baseline_mtime" ]; then
                steady_secs=$((steady_secs + POLL_BUSY))
            else
                baseline_mtime="$oldest_mtime"
                baseline_procs="$procs"
                steady_secs=0
            fi

            if [ "$steady_secs" -ge "$STEADY_THRESHOLD" ] && [ -n "$oldest_stale" ]; then
                log "STEADY-STATE TIMEOUT (${steady_secs}s unchanged mtime) — removing stuck ref lock ($oldest_stale, procs=${procs})"
                if rm "$oldest_stale" 2>/dev/null; then
                    continue
                else
                    log "ERROR: failed to remove stuck ref lock: $oldest_stale"
                    return 2
                fi
            fi

            poll="$POLL_BUSY"
            log "wait cycle $cycle: ref lock(s) present, git procs=${procs} (steady=${steady_secs}s, baseline_procs=${baseline_procs}) — waited ${waited}s"
        fi
        sleep "$poll"
        waited=$((waited + poll))
    done
}

wait_for_refs_clear || {
    log "ERROR: ref locks never cleared after ${MAX_WAIT}s, giving up"
    exit 2
}

tmpfile=$(mktemp 2>/dev/null || echo "/tmp/git_safe_push.$$")
trap 'rm -f "$tmpfile"' EXIT

git push "$@" 2> >(tee "$tmpfile" >&2)
rc=$?

if [ "$rc" -ne 0 ] && grep -qE "\.lock|unable to create.*lock" "$tmpfile" 2>/dev/null; then
    log "push hit a lock race (exit $rc) — retrying once in 5s"
    sleep 5
    wait_for_refs_clear || true
    git push "$@"
    rc=$?
fi

exit "$rc"
