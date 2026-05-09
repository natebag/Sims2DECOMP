// 0x80203D30 (56B) INVTarget::GetSelectedShoppingCategory(void)
// ASMPROC_replace_insn: match="lwzx 3,3,9" replacement="lwzx 3,9,3"

struct INVTarget {
    char pad[376];
    int* m_categories;

    int GetSelectedShoppingCategoryListIdx();
    int GetSelectedShoppingCategory();
};

int INVTarget::GetSelectedShoppingCategory() {
    int idx = GetSelectedShoppingCategoryListIdx();
    return *(int*)(idx * 8 + (char*)m_categories);
}
