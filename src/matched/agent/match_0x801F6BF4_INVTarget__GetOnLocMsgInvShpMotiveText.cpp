// 0x801F6BF4 INVTarget::GetOnLocMsgInvShpMotiveText(unsigned wchar_t *) (104B)

namespace InteractorModule {
    struct ShoppingItem { char data[8]; };
}

class INVTarget {
public:
    char _pad0[12881];
    unsigned char m_someByte;

    void GetSelectedShoppingItem(int b, InteractorModule::ShoppingItem& out, int& idx);
    void GetMotiveText(int i, InteractorModule::ShoppingItem* item, unsigned short* out);
    void GetOnLocMsgInvShpMotiveText(unsigned short* out);
};

void INVTarget::GetOnLocMsgInvShpMotiveText(unsigned short* out) {
    if (out == 0) return;
    *out = 0;
    InteractorModule::ShoppingItem item;
    int idx = 0;
    GetSelectedShoppingItem(m_someByte, item, idx);
    GetMotiveText(idx, &item, out);
}
