/* M2MTarget::CalcNumItems(void) at 0x801C2A24 (80B) */

struct M2MTarget {
    struct ResultStruct {
        int field0;
        int field4;
        int field8;
    };

    int OnGetNumItems(ResultStruct& rs);

    char pad_000[0x10C];
    ResultStruct m_resultStruct;
    char pad_118[0x168 - 0x118];
    int m_field168;
    char pad_16C[0x188 - 0x16C];
    int m_field188;

    void CalcNumItems();
};

void M2MTarget::CalcNumItems() {
    if (m_field168 == 0) {
        m_field188 = 1;
    } else {
        m_field188 = OnGetNumItems(m_resultStruct);
    }
}
