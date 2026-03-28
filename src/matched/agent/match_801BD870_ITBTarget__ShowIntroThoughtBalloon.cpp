class ITBTarget {
public:
    char _pad[0x98];
    int m_isActive;

    void ShowIntroThoughtBalloon(void);
};

void ITBTarget::ShowIntroThoughtBalloon(void) {
    m_isActive = 1;
}
