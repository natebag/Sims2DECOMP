// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 44B: skill rating getter wall. Parked S12.
// Original path: src/matched/skills/match_0x801D1AD0_IsSkillCatalogRating.cpp
//
// 0x801D1AD0 IsSkillCatalogRating (44B)
// FLAGS: -Os

int IsSkillCatalogRating(int id) {
    if (id < 0) return 1;
    if (id <= 6) return 0;
    int result = 1;
    if (id <= 13) return result;
    return result;
}
