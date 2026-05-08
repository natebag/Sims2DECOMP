#!/bin/bash
# size_sweep.sh — Detect header size-label mismatches across match_*.cpp files
#
# For each match file in the given git range (or working tree), extract the
# address and the header-declared size, look up the map-declared size in the
# DVD map, and flag mismatches.
#
# This catches the class of fake/buggy matches where the file's comment says
# "(64B)" but the real function at that address is 84B — byte-matching only the
# first 64B or diverging partway through.
#
# Usage:
#   ./tools/size_sweep.sh                  # sweep all match_*.cpp in src/matched/
#   ./tools/size_sweep.sh <git-range>      # only files in commits in range, e.g., 1d50fa8b..HEAD
#
# Exit code:
#   0 — all files match OR skipped (missing header)
#   1 — one or more MISMATCH found
#
# Notes:
# - Skips files that lack a canonical "(NN B)" header comment. Those are
#   pre-QA-RULE-1 legacy files and are the separate "4,312 headerless backfill"
#   concern, not a mislabel incident.
# - Map source: extracted/files/u2_ngc_release_dvd.map (cm3-build22 DVD map).
#   If the release map (cm3-build25) is used the results will be wrong — per
#   memory:project_dvd_map_discovery.md.
#
# Promoted from OpusReview's /tmp/size_sweep.sh during S13 pre-session
# housekeeping, 2026-04-21. Canonical shared infra per
# memory:feedback_review_shared_infra.md.

set +e  # iterate all files even if one errors

MAP="extracted/files/u2_ngc_release_dvd.map"
if [ ! -f "$MAP" ]; then
    echo "ERROR: DVD map not found at $MAP" >&2
    exit 2
fi

# Scope: all working-tree files if no arg, or git diff files in a range.
if [ $# -eq 0 ]; then
    FILES=$(find src/matched -name 'match_*.cpp' 2>/dev/null)
    SCOPE="src/matched (working tree)"
elif [ $# -eq 1 ]; then
    RANGE="$1"
    FILES=$(git diff --name-only --diff-filter=AM "$RANGE" 2>/dev/null | grep 'src/matched/match_\|src/matched/.*/match_' | grep '\.cpp$')
    SCOPE="git range $RANGE"
else
    echo "Usage: $0 [<git-range>]" >&2
    exit 2
fi

if [ -z "$FILES" ]; then
    echo "No match_*.cpp files found in $SCOPE"
    exit 0
fi

TOTAL=0
CLEAN=0
MISMATCH=0
SKIP=0
MISMATCH_LIST=""

for f in $FILES; do
    [ -f "$f" ] || continue
    TOTAL=$((TOTAL + 1))

    # Extract address from filename (match_0xADDR_...).
    ADDR=$(basename "$f" | sed -n 's/^match_\(0x\)\?\([0-9a-fA-F]\+\)_.*/\2/p')
    if [ -z "$ADDR" ]; then
        SKIP=$((SKIP + 1))
        continue
    fi

    # Extract declared size from first 5 lines, pattern "(NN B)" or "(NN b)" or "(NN bytes)".
    DECLARED=$(head -5 "$f" | grep -oE '\([0-9]+ ?[bB](ytes)?\)' | head -1 | grep -oE '[0-9]+')
    if [ -z "$DECLARED" ]; then
        SKIP=$((SKIP + 1))
        continue
    fi

    # Look up map size. The DVD map has TWO lines per address:
    #   1. File/section line  ("addr bigsize 4 <path>.obj")
    #   2. Symbol line        ("addr funcsize 0 <Class>::<method>(...)")  ← what we want
    # The symbol line is always LAST (sorted by depth). Use tail -1.
    MAP_HEX=$(grep -i "^${ADDR}[[:space:]]" "$MAP" 2>/dev/null | awk '{print $2}' | tail -1)
    if [ -z "$MAP_HEX" ]; then
        SKIP=$((SKIP + 1))
        continue
    fi

    MAP_DEC=$((16#$MAP_HEX))

    if [ "$DECLARED" = "$MAP_DEC" ]; then
        CLEAN=$((CLEAN + 1))
    else
        MISMATCH=$((MISMATCH + 1))
        MISMATCH_LIST="${MISMATCH_LIST}
MISMATCH: $f declared=${DECLARED}B map=${MAP_DEC}B (0x${MAP_HEX})"
    fi
done

echo "====== size_sweep: $SCOPE ======"
echo "TOTAL=$TOTAL CLEAN=$CLEAN MISMATCH=$MISMATCH SKIP=$SKIP (no-header-or-not-in-map)"
if [ "$MISMATCH" -gt 0 ]; then
    echo "$MISMATCH_LIST"
    echo ""
    echo "SWEEP: $MISMATCH mislabels found"
    exit 1
fi
echo "SWEEP: 0 mislabels"
exit 0
