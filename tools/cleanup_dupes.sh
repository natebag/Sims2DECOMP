#!/bin/bash
# Cleanup script for duplicate match files
# Run from repo root: bash tools/cleanup_dupes.sh

# Duplicate pairs found - keeping the first (shorter/better name), deleting the second

echo "Cleaning up 9 duplicate pairs..."

# 0x80029580 - Keep EIFenceWall_VisibilityTest, delete EIFenceWall__VisibilityTest
rm -f "src/matched/agent/match_0x80029580_EIFenceWall__VisibilityTest.cpp"

# 0x8003D880 - Keep GameData_UseConfigOptions, delete GameData__UseConfigOptions
rm -f "src/matched/agent/match_0x8003D880_GameData__UseConfigOptions.cpp"

# 0x80041788 - Keep EGlobal_LoadSelectorData, delete EGlobal__LoadSelectorData
rm -f "src/matched/agent/match_0x80041788_EGlobal__LoadSelectorData.cpp"

# 0x8009F038 - Keep BString__find, delete BString__find_charptr
rm -f "src/matched/agent/match_0x8009F038_BString__find_charptr.cpp"

# 0x8009F190 - Keep BString__find_variant, delete BString__rfind
rm -f "src/matched/agent/match_0x8009F190_BString__rfind.cpp"

# 0x8009F338 - Keep BString__find_first_of, delete BString__find_variant (duplicate)
rm -f "src/matched/agent/match_0x8009F338_BString__find_variant.cpp"

# 0x8009F428 - Keep BString__find_last_of, delete BString__find_variant (duplicate)
rm -f "src/matched/agent/match_0x8009F428_BString__find_variant.cpp"

# 0x8009F518 - Keep BString__find_first_not_of, delete BString__find_variant (duplicate)
rm -f "src/matched/agent/match_0x8009F518_BString__find_variant.cpp"

# 0x8009F660 - Keep BString__find_last_not_of, delete BString__find_variant (duplicate)
rm -f "src/matched/agent/match_0x8009F660_BString__find_variant.cpp"

echo "Cleanup complete. 9 duplicate files removed."
echo "Verifying no duplicates remain..."

# Verification
dupe_count=$(find src/matched/ -name "*.cpp" -printf "%f\n" 2>/dev/null | sed -E 's/^match_//' | sed -E 's/^0x//' | grep -oE '^[0-9A-Fa-f]{8}' | sort | uniq -d | wc -l)
echo "Remaining duplicates: $dupe_count"
