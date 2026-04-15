/* AptDisplayList::PreDestroy(void) - 0x8029B9A0 (76B) */

struct AptCIH;
struct AptDisplayListState {
    ~AptDisplayListState();
};

class AptDisplayList {
public:
    AptDisplayListState* m_state;  // +0

    void clear(bool);
    void PreDestroy(void);
};

void AptDisplayList::PreDestroy(void) {
    clear(false);
    AptDisplayListState* state = m_state;
    if (state != 0) {
        delete state;
    }
    m_state = 0;
}
