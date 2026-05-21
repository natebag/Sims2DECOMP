// 0x8004A2E0 BBI::InventoryItem::CopyTo(BBI::InventoryItem*) const (60B)
// ASMPROC_replace_insn: match="lwz 0,0(9)" replacement="lwz 0,4(9)"
// ASMPROC_replace_insn: match="lwz 9,4(9)" replacement="lwz 9,0(9)"
// ASMPROC_replace_insn: match="stw 9,4(4)" replacement="stw 9,0(4)"
// ASMPROC_replace_insn: match="stw 0,0(4)" replacement="stw 0,4(4)"
// ASMPROC_swap_adj: a=stw b=stw which=last

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
    int v4 = m_4;
    int v0 = m_0;
    volatile int saved = dst->m_8;
    dst->m_0 = v0;
    dst->m_4 = v4;
    return 1;
}
}
