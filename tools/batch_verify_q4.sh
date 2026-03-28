#!/bin/bash
# Batch verify all Q4 targets
cd "$(dirname "$0")/.."

matched=0
failed=0
total=0
errors=""

while IFS=' ' read -r addr size name; do
    # Find the matching file
    prefix="match_${addr}_"
    file=$(ls src/matched/agent/${prefix}*.cpp 2>/dev/null | head -1)
    if [ -z "$file" ]; then
        continue
    fi
    
    total=$((total+1))
    result=$(bash tools/verify_match.sh "$file" "$addr" "$size" 2>&1)
    if echo "$result" | grep -q "MATCH!"; then
        matched=$((matched+1))
    else
        failed=$((failed+1))
        errors="$errors\nFAIL: $addr $name"
        if [ $failed -le 3 ]; then
            echo "FAIL: $addr $name"
            echo "$result" | tail -5
        fi
    fi
    
    # Print progress every 50
    if [ $((total % 50)) -eq 0 ]; then
        echo "[Progress] $total checked, $matched matched, $failed failed"
    fi
done < build/agent3_q4_targets.txt

echo ""
echo "=== FINAL RESULTS ==="
echo "Total verified: $total"
echo "Matched: $matched"
echo "Failed: $failed"
