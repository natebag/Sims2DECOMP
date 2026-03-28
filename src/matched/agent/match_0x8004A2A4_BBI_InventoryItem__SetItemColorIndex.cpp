namespace BBI {

struct InventoryItem {
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int* m_vtable;

    unsigned char GetItemColorIndex() const;
    void SetItemColorIndex(unsigned char idx);
};

void InventoryItem::SetItemColorIndex(unsigned char idx) {
    GetItemColorIndex();
    m_colorIndex = idx;
}

}
