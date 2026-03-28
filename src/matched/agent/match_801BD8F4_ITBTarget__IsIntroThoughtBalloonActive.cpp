class ITBTarget {
public:
    char _pad[0x88];
    int m_isVisible;

    int IsIntroThoughtBalloonActive(void);
};

int ITBTarget::IsIntroThoughtBalloonActive(void) {
    return m_isVisible;
}
