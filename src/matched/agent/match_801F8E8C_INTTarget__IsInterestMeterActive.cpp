class INTTarget {
public:
    char pad[0x88];
    int m_isInterestMeterActive;
    int IsInterestMeterActive(void);
};

int INTTarget::IsInterestMeterActive(void) {
    return m_isInterestMeterActive;
}
