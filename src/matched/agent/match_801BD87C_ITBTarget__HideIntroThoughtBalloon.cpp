class ITBTarget {
public:
    char _pad[0x98];
    int m_showBalloon;

    void HideIntroThoughtBalloon();
};

void ITBTarget::HideIntroThoughtBalloon() {
    m_showBalloon = 0;
}
