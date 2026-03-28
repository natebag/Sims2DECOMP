/* MMUTarget::UpdateNumberOfPlayersChoice(char *, char *) at 0x801C78F4 (68B) */

int AtoI(char*);

struct MMUTarget {
    char pad_000[0xC0];
    int m_numPlayersChoice;
    int m_numPlayersOldChoice;

    void UpdateNumberOfPlayersChoice(char* key, char* value);
    void OnNumberOfPlayersChoiceChange();
};

void MMUTarget::UpdateNumberOfPlayersChoice(char* key, char* value) {
    int newChoice = AtoI(value);
    int oldChoice = m_numPlayersChoice;
    m_numPlayersChoice = newChoice;
    m_numPlayersOldChoice = oldChoice;
    OnNumberOfPlayersChoiceChange();
}
