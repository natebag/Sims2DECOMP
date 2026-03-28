/* MMUTarget::UpdateGameplayChoice(char *, char *) at 0x801C78B0 (68B) */

int AtoI(char*);

struct MMUTarget {
    char pad_000[0xB8];
    int m_gameplayChoice;
    int m_gameplayOldChoice;

    void UpdateGameplayChoice(char* key, char* value);
    void OnGameplayLevelChoiceChange();
};

void MMUTarget::UpdateGameplayChoice(char* key, char* value) {
    int newChoice = AtoI(value);
    int oldChoice = m_gameplayChoice;
    m_gameplayChoice = newChoice;
    m_gameplayOldChoice = oldChoice;
    OnGameplayLevelChoiceChange();
}
