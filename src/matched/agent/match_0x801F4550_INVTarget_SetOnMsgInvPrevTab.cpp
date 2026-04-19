// 0x801F4550 (52B) INVTarget::SetOnMsgInvPrevTab(char*)
// Read member tab-index, look up previous-tab from SDA int array
// (SDA21: addi r9,r13,-28708 then lwzx), decrement, dispatch to
// OnSetCurrentTab.

extern int g_prevTabArray[2];

class INVTarget {
public:
    char pad_000[0x84];
    int m_field_084;
    void SetOnMsgInvPrevTab(char*);
    void OnSetCurrentTab(int);
};

void INVTarget::SetOnMsgInvPrevTab(char*) {
    OnSetCurrentTab(g_prevTabArray[m_field_084] - 1);
}
