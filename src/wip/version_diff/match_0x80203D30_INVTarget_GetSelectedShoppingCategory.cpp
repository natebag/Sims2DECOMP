// 0x80203D30 (56B) INVTarget::GetSelectedShoppingCategory(void)

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
