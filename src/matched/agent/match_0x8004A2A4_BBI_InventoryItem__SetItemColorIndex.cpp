/* BBI::InventoryItem::SetItemColorIndex(unsigned char) at 0x8004A2A4 (52B) */

struct BBI_II_SICI {
    unsigned char m_cat;
    unsigned char m_unk1;
    unsigned char m_color;
    unsigned char m_subcat;
    void CheckOrLock();
    void SetItemColorIndex(unsigned char ci);
};

void BBI_II_SICI::SetItemColorIndex(unsigned char ci) {
    CheckOrLock();
    m_color = ci;
}
