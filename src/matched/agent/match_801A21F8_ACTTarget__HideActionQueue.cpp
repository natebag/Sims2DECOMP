class ACTTarget {
public:
    char _pad[0xD8];
    int m_actionQueueVisible;

    void HideActionQueue(void);
};

void ACTTarget::HideActionQueue(void) {
    m_actionQueueVisible = 0;
}
