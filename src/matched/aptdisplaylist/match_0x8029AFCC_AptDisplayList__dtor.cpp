// 0x8029AFCC (88B) AptDisplayList::~AptDisplayList(void)

struct AptDisplayListState {
    void Release(int);
};

struct AptDisplayList {
    AptDisplayListState* m_state;
    void clear(bool);
    ~AptDisplayList();
};

AptDisplayList::~AptDisplayList() {
    clear(false);
    if (m_state) {
        m_state->Release(3);
    }
}
