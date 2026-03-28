namespace BBI {

struct InventoryItem {
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int* m_vtable;

    typedef int eItemSubcategory;
    eItemSubcategory GetItemSubcategory() const;
    void SetItemSubcategory(eItemSubcategory sub);
};

void InventoryItem::SetItemSubcategory(eItemSubcategory sub) {
    GetItemSubcategory();
    m_subcategory = sub;
}

}
