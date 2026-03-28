namespace BBI {

extern int InventoryItem_vtable[];

struct InventoryItem {
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int* m_vtable;

    InventoryItem();
};

InventoryItem::InventoryItem() {
    m_vtable = InventoryItem_vtable;
    m_subcategory = 0;
    m_guid = 0;
    m_category = 0;
    m_count = 0;
    m_colorIndex = 0;
}

}
