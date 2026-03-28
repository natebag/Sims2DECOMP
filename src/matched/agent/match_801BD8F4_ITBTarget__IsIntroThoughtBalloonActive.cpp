class ITBTarget {
public:
    char _pad[0x88];
    int m_isActive;

    int IsIntroThoughtBalloonActive();
};

int ITBTarget::IsIntroThoughtBalloonActive() {
    return m_isActive;
}
