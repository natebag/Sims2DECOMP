/* BBI::InventoryItem::SetItemCategory(BBI::InventoryItem::eItemCategory) at 0x8004A0C4 (52B) */

struct BBI_II_SIC {
    unsigned char m_cat;
    unsigned char m_unk1;
    unsigned char m_color;
    unsigned char m_subcat;
    int m_guid;
    void CheckOrLock();
    void SetItemCategory(int cat);
};

void BBI_II_SIC::SetItemCategory(int cat) {
    CheckOrLock();
    m_cat = (unsigned char)cat;
}
