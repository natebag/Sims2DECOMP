class ITBTarget {
public:
    char _pad[0x98];
    int m_showBalloon;

    void ShowIntroThoughtBalloon();
};

void ITBTarget::ShowIntroThoughtBalloon() {
    m_showBalloon = 1;
}
