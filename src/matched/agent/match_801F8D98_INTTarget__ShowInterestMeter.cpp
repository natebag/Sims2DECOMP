class INTTarget {
public:
    char pad[0x94];
    int m_showInterestMeter;
    void ShowInterestMeter(void);
};

void INTTarget::ShowInterestMeter(void) {
    m_showInterestMeter = 1;
}
