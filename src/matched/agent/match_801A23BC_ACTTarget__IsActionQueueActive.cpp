class ACTTarget {
public:
    char _pad[0xD0];
    int m_isActive;

    int IsActionQueueActive();
};

int ACTTarget::IsActionQueueActive() {
    return m_isActive;
}
