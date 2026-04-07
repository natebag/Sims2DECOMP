#!/usr/bin/env bash
# Install repo hooks into .git/hooks/
# Run once after cloning the Sims 2 GC decomp repo.
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(git rev-parse --show-toplevel)"
HOOK_SRC="$SCRIPT_DIR/hooks/pre-commit"
HOOK_DST="$REPO_ROOT/.git/hooks/pre-commit"

if [ ! -f "$HOOK_SRC" ]; then
    echo "ERROR: $HOOK_SRC not found" >&2
    exit 1
fi

cp "$HOOK_SRC" "$HOOK_DST"
chmod +x "$HOOK_DST"
echo "Installed pre-commit hook -> $HOOK_DST"
echo ""
echo "The hook runs verify_match.sh on every src/matched/**/*.cpp commit."
echo "  MATCH         -> committed"
echo "  MISMATCH      -> auto-moved to src/wip/version_diff/"
echo "  COMPILE_FAIL  -> BLOCKED with diagnostic"
echo "  HEADER bad    -> BLOCKED (canonical header required)"
echo "  inline asm    -> BLOCKED (FAKE)"
echo ""
echo "Emergency bypass (logged): SKIP_VERIFY=1 git commit ..."
