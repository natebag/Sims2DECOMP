class MMUTarget {
public:
    char pad[0xB8];
    int m_currentGameplayChoice;
    int GetCurrentGameplayChoice(void) const;
};

int MMUTarget::GetCurrentGameplayChoice(void) const {
    return m_currentGameplayChoice;
}
