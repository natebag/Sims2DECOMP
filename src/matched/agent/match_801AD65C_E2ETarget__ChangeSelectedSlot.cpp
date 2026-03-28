int AtoI(char *);

class E2ETarget {
public:
    char _pad[0xB4];
    int m_maxSlots;
    char _pad2[8];
    int m_selectedSlot;

    void ChangeSelectedSlot(char *, char *);
};

void E2ETarget::ChangeSelectedSlot(char *a, char *b) {
    int val = AtoI(b);
    if (val < 0) {
        m_selectedSlot = m_maxSlots - 1;
    } else if (val >= m_maxSlots) {
        m_selectedSlot = 0;
    } else {
        m_selectedSlot = val;
    }
}
