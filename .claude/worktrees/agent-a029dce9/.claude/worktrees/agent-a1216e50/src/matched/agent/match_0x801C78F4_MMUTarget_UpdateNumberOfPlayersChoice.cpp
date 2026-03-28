/* MMUTarget::UpdateNumberOfPlayersChoice - 0x801C78F4 - 68 bytes */

extern int atoi(const char *);

struct MMUTarget {
    char pad[0xC0];
    int m_numPlayersChoice;
    int m_prevNumPlayersChoice;
    void UpdateNumberOfPlayersChoice(char *key, char *val);
    void UpdateNumPlayersMenuState(void);
};

void MMUTarget::UpdateNumberOfPlayersChoice(char *key, char *val)
{
    int newVal = atoi(val);
    int oldVal = m_numPlayersChoice;
    m_numPlayersChoice = newVal;
    m_prevNumPlayersChoice = oldVal;
    UpdateNumPlayersMenuState();
}
