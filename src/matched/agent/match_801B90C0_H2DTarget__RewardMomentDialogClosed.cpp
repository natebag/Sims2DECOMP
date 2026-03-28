class H2DTarget {
public:
    char _pad[0xE0];
    int m_rewardDialogClosed;

    void RewardMomentDialogClosed(void);
};

void H2DTarget::RewardMomentDialogClosed(void) {
    m_rewardDialogClosed = 1;
}
