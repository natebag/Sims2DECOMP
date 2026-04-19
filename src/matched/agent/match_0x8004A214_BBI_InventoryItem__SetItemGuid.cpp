/* BBI::InventoryItem::SetItemGuid(int) at 0x8004A214 (52B) */

struct BBI_II_SIG {
    unsigned char m_cat;
    unsigned char m_unk1;
    unsigned char m_color;
    unsigned char m_subcat;
    int m_guid;
    void CheckOrLock();
    void SetItemGuid(int guid);
};

void BBI_II_SIG::SetItemGuid(int guid) {
    CheckOrLock();
    m_guid = guid;
}
