class WAFTarget {
public:
    char pad[0x88];
    int m_isWantsAndFearsActive;
    int IsWantsAndFearsActive(void);
};

int WAFTarget::IsWantsAndFearsActive(void) {
    return m_isWantsAndFearsActive;
}
