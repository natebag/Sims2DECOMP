/* M2MTarget::PopButtonFilters(void) at 0x801C2F6C (96B) */

struct UIObjectBase {
    static void popAptButtonFilter(int, unsigned int);
};

struct M2MTarget {
    char pad_000[0x170];
    unsigned int m_buttonFilter0;
    unsigned int m_buttonFilter1;

    void PopButtonFilters();
};

void M2MTarget::PopButtonFilters() {
    if (m_buttonFilter0 != 0) {
        UIObjectBase::popAptButtonFilter(0, m_buttonFilter0);
        m_buttonFilter0 = 0;
    }
    if (m_buttonFilter1 != 0) {
        UIObjectBase::popAptButtonFilter(1, m_buttonFilter1);
        m_buttonFilter1 = 0;
    }
}
