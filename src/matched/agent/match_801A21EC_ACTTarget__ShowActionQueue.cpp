class ACTTarget {
public:
    char _pad[0xD8];
    int m_actionQueueVisible;

    void ShowActionQueue(void);
};

void ACTTarget::ShowActionQueue(void) {
    m_actionQueueVisible = 1;
}
