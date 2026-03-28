class ITBTarget {
public:
    char _pad[0x98];
    int m_isActive;

    void HideIntroThoughtBalloon(void);
};

void ITBTarget::HideIntroThoughtBalloon(void) {
    m_isActive = 0;
}
