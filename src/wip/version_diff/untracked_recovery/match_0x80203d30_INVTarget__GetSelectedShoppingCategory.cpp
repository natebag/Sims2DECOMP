// 0x80203D30 INVTarget::GetSelectedShoppingCategory (56B)

struct INVTarget {
    char pad[376];
    int* m_categories;
    int GetSelectedShoppingCategoryListIdx();
    int GetSelectedShoppingCategory();
};

struct CategoryEntry {
    int value;
    int pad;
};

int INVTarget::GetSelectedShoppingCategory() {
    int idx = GetSelectedShoppingCategoryListIdx();
    CategoryEntry* entries = (CategoryEntry*)m_categories;
    return entries[idx].value;
}
