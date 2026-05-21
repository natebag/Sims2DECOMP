// 0x801C3DA0 MDITarget::AddToList(MDITarget::ModelessDialog*) (80B)
// TRIAGE

class MDITarget {
public:
    struct ModelessDialog {
        char pad_00[32];
        ModelessDialog* m_next;
    };

    char pad_00[132];
    ModelessDialog* m_head;
    int             m_count;

    void AddToList(ModelessDialog* d);
};

void MDITarget::AddToList(ModelessDialog* d) {
    ModelessDialog* p = m_head;
    m_count = 1;
    if (p == 0) {
        m_head = d;
        return;
    }
    int n = 2;
    while (true) {
        m_count = n;
        if (p->m_next == 0) break;
        n = m_count;
        p = p->m_next;
        n++;
    }
    p->m_next = d;
    d->m_next = 0;
}
