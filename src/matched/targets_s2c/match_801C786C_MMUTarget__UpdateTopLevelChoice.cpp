/* MMUTarget::UpdateTopLevelChoice(char *, char *) at 0x801C786C (68B) */

int AtoI(char*);

struct MMUTarget {
    char pad_000[0xA4];
    int m_topLevelChoice;
    int m_topLevelOldChoice;

    void UpdateTopLevelChoice(char* key, char* value);
    void OnTopLevelChoiceChange();
};

void MMUTarget::UpdateTopLevelChoice(char* key, char* value) {
    int newChoice = AtoI(value);
    int oldChoice = m_topLevelChoice;
    m_topLevelChoice = newChoice;
    m_topLevelOldChoice = oldChoice;
    OnTopLevelChoiceChange();
}
