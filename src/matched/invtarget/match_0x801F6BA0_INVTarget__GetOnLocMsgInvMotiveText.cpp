// 0x801F6BA0 INVTarget::GetOnLocMsgInvMotiveText(unsigned wchar_t *) (84B)

namespace BBI { class InventoryItem; }

extern int gv_INVTarget_state_table[2];

class INVTarget {
public:
    char _pad0[132];
    int m_modeIdx;
    char _pad[216 - 136];
    void* m_items[1];

    void GetMotiveText(BBI::InventoryItem*, unsigned short*);
    void GetOnLocMsgInvMotiveText(unsigned short* out);
};

void INVTarget::GetOnLocMsgInvMotiveText(unsigned short* out) {
    if (out == 0) return;
    *out = 0;
    int state = gv_INVTarget_state_table[m_modeIdx];
    BBI::InventoryItem* item = (BBI::InventoryItem*)m_items[state];
    GetMotiveText(item, out);
}
