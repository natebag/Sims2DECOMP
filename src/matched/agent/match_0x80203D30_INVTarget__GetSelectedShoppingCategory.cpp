// 0x80203D30 (56B) INVTarget::GetSelectedShoppingCategory(void)
// ASMPROC_swap_operands: match="lwzx 3,3,9" pos=1,2

struct INVTarget {
    char pad[376];
    int* m_categories;

    int GetSelectedShoppingCategoryListIdx();
    int GetSelectedShoppingCategory();
};

int INVTarget::GetSelectedShoppingCategory() {
    int idx = GetSelectedShoppingCategoryListIdx();
    return *(int*)((char*)m_categories + idx * 8);
}
