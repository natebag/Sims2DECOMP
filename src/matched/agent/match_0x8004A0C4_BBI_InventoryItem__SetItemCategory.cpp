namespace BBI {

struct InventoryItem {
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int* m_vtable;

    typedef int eItemCategory;
    eItemCategory GetItemCategory() const;
    void SetItemCategory(eItemCategory cat);
};

void InventoryItem::SetItemCategory(eItemCategory cat) {
    GetItemCategory();
    m_category = cat;
}

}
