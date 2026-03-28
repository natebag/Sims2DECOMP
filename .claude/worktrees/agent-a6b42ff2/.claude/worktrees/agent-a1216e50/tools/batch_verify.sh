#!/bin/bash
# batch_verify.sh - Verify all raw-byte match files in src/matched/agent/
# Usage: bash tools/batch_verify.sh [pattern]
# Example: bash tools/batch_verify.sh "0x8024"

set -e

PATTERN="${1:-0x802}"
MATCH_COUNT=0
FAIL_COUNT=0
SKIP_COUNT=0
TOTAL=0

for f in src/matched/agent/match_${PATTERN}*.cpp; do
    [ -f "$f" ] || continue

    # Extract address and size from the file header comment
    ADDR=$(grep -oE '0x[0-9a-fA-F]+' <<< "$(basename "$f")" | head -1)
    SIZE=$(head -1 "$f" | grep -oE '[0-9]+ bytes' | grep -oE '[0-9]+')

    if [ -z "$ADDR" ] || [ -z "$SIZE" ]; then
        echo "SKIP $f - could not parse addr/size"
        SKIP_COUNT=$((SKIP_COUNT + 1))
        continue
    fi

    TOTAL=$((TOTAL + 1))

    # Run verify silently
    if bash tools/verify_match.sh "$f" "$ADDR" "$SIZE" > /dev/null 2>&1; then
        MATCH_COUNT=$((MATCH_COUNT + 1))
    else
        echo "FAIL $f ($ADDR $SIZE)"
        FAIL_COUNT=$((FAIL_COUNT + 1))
    fi

    # Print progress every 50
    if [ $((TOTAL % 50)) -eq 0 ]; then
        echo "[Progress] $TOTAL checked | $MATCH_COUNT matched | $FAIL_COUNT failed"
    fi
done

echo ""
echo "=== RESULTS ==="
echo "Total: $TOTAL | Matched: $MATCH_COUNT | Failed: $FAIL_COUNT | Skipped: $SKIP_COUNT"
