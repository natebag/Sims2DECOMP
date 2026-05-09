// IsSkillCatalogRating(int) - 0x801D1AD0 (44B)
// Returns true unless 0 <= rating <= 6.

bool IsSkillCatalogRating(int rating)
{
    if (rating >= 0) {
        if (rating <= 6) return false;
        if (rating <= 13) return true;
    }
    return true;
}
