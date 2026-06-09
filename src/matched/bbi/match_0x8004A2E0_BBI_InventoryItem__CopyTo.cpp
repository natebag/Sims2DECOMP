// 0x8004A2E0 BBI::InventoryItem::CopyTo(BBI::InventoryItem*) const (60B)
namespace BBI {
class InventoryItem {
public:
    int m_0;
    int m_4;
    int m_8;
    int CopyTo(InventoryItem* dst) const;
};

int InventoryItem::CopyTo(InventoryItem* dst) const {
    if (dst == 0) return 0;
    int v0 = m_0;
    int v4 = m_4;
    dst->m_4 = v4;
    volatile int saved = dst->m_8;
    dst->m_0 = v0;
    return 1;
}
}
