class H2DTarget {
public:
    char _pad[0xE0];
    int m_rewardMomentDialogClosed;

    void RewardMomentDialogClosed();
};

void H2DTarget::RewardMomentDialogClosed() {
    m_rewardMomentDialogClosed = 1;
}
