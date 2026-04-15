// 0x8004A2E0 BBI::InventoryItem::CopyTo(BBI::InventoryItem *) const (60B)

namespace BBI {

class InventoryItem {
public:
    char m_category;
    char m_count;
    char m_colorIndex;
    char m_subcategory;
    int m_guid;
    int m_vtable_placeholder;
    int CopyTo(InventoryItem* dest) const;
};

int InventoryItem::CopyTo(InventoryItem* dest) const {
    if (dest) {
        volatile int* p = (volatile int*)((char*)dest + 8);
        int saved = *p;
        *(long long*)dest = *(long long*)this;
        *p = saved;
        return 1;
    }
    return 0;
}

}
