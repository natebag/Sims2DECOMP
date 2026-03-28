class WAFTarget {
public:
    char pad[0x90];
    int m_showWantsAndFears;
    void ShowWantsAndFears(void);
};

void WAFTarget::ShowWantsAndFears(void) {
    m_showWantsAndFears = 1;
}
