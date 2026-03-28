class INTTarget {
public:
    char pad[0x94];
    int m_showInterestMeter;
    void HideInterestMeter(void);
};

void INTTarget::HideInterestMeter(void) {
    m_showInterestMeter = 0;
}
