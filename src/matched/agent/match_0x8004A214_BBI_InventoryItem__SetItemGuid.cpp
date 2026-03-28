namespace BBI {

struct InventoryItem {
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int* m_vtable;

    int GetItemGuid() const;
    void SetItemGuid(int guid);
};

void InventoryItem::SetItemGuid(int guid) {
    GetItemGuid();
    m_guid = guid;
}

}
