#!/bin/bash
# git_safe_push.sh — wrap `git push` with stale-lock detection and retry.
#
# Push doesn't touch .git/index.lock, but it does acquire per-ref locks
# under .git/refs/remotes/<remote>/<branch>.lock when updating tracking refs.
# Fleet contention can leave those orphaned too. Same retry pattern as
# git_safe_commit.sh, adapted to per-ref locks.
#
# Usage: tools/git_safe_push.sh [same args as git push]

set -u

MAX_WAIT=60
POLL_FRESH=2
POLL_BUSY=5
STALE_AGE=30

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

wait_for_refs_clear() {
    local waited=0 locks age poll oldest_stale
    while true; do
        locks=$(find_ref_locks)
        if [ -z "$locks" ]; then return 0; fi
        if [ "$waited" -ge "$MAX_WAIT" ]; then return 1; fi

        oldest_stale=""
        local any_fresh=0
        while IFS= read -r f; do
            [ -z "$f" ] && continue
            age=$(lock_age_secs "$f")
            [ -z "$age" ] && continue
            if [ "$age" -lt "$STALE_AGE" ]; then
                any_fresh=1
            else
                oldest_stale="$f"
            fi
        done <<< "$locks"

        if [ "$any_fresh" -eq 1 ]; then
            poll="$POLL_FRESH"
            log "ref lock(s) present (fresh) — waited ${waited}s, polling in ${poll}s"
        else
            local procs
            procs=$(git_proc_count)
            if [ "${procs:-0}" -eq 0 ] && [ -n "$oldest_stale" ]; then
                log "STALE REF LOCK DETECTED ($oldest_stale, no git procs) — removing"
                if rm "$oldest_stale" 2>/dev/null; then
                    continue
                else
                    log "ERROR: failed to remove stale ref lock: $oldest_stale"
                    return 2
                fi
            fi
            poll="$POLL_BUSY"
            log "ref lock(s) present (${procs:-0} git procs running) — waited ${waited}s, polling in ${poll}s"
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
