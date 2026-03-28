/* MMUTarget::UpdateGameplayChoice - 0x801C78B0 - 68 bytes */

extern int atoi(const char *);

struct MMUTarget {
    char pad[0xB8];
    int m_gameplayChoice;
    int m_prevGameplayChoice;
    void UpdateGameplayChoice(char *key, char *val);
    void UpdateGameplayMenuState(void);
};

void MMUTarget::UpdateGameplayChoice(char *key, char *val)
{
    int newVal = atoi(val);
    int oldVal = m_gameplayChoice;
    m_gameplayChoice = newVal;
    m_prevGameplayChoice = oldVal;
    UpdateGameplayMenuState();
}
