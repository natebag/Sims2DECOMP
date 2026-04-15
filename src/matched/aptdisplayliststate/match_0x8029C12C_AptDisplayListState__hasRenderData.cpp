/* AptDisplayListState::hasRenderData(void) - 0x8029C12C (88B) */

struct AptCIH {
    char pad[84];
    AptCIH* m_next;

    int hasRenderData(void);
};

class AptDisplayListState {
public:
    AptCIH* m_head;

    int hasRenderData(void);
};

int AptDisplayListState::hasRenderData(void) {
    AptCIH* p = m_head;
    while (p != 0) {
        if (p->hasRenderData() != 0) return 1;
        p = p->m_next;
    }
    return 0;
}
