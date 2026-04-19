/* BBI::InventoryItem::SetItemSubcategory(BBI::InventoryItem::eItemSubcategory) at 0x8004A104 (52B) */

struct BBI_II_SISC {
    unsigned char m_cat;
    unsigned char m_unk1;
    unsigned char m_color;
    unsigned char m_subcat;
    void CheckOrLock();
    void SetItemSubcategory(int subcat);
};

void BBI_II_SISC::SetItemSubcategory(int subcat) {
    CheckOrLock();
    m_subcat = (unsigned char)subcat;
}
