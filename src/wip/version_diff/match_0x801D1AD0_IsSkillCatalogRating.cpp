/* IsSkillCatalogRating(int) at 0x801D1AD0 (44B) */

int IsSkillCatalogRating(int rating) {
    if (rating < 0) return 1;
    if (rating <= 6) return 0;
    if (rating <= 13) return 1;
    return 1;
}
