class MMUTarget {
public:
    char pad[0xA4];
    int m_currentMainScreenChoice;
    int GetCurrentMainScreenChoice(void) const;
};

int MMUTarget::GetCurrentMainScreenChoice(void) const {
    return m_currentMainScreenChoice;
}
