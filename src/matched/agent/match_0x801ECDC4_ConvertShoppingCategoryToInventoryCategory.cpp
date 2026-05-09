// ConvertShoppingCategoryToInventoryCategory(int) - 0x801ECDC4 (44B)
// Range mapping: <0 -> 0, 0..8 -> 1, 9..13 -> 2, >13 -> 0.

int ConvertShoppingCategoryToInventoryCategory(int cat)
{
    if (cat >= 0) {
        if (cat <= 8) return 1;
        if (cat <= 13) return 2;
    }
    return 0;
}
