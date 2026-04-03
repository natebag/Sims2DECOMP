/* MMUTarget::UpdateTopLevelChoice - 0x801C786C - 68 bytes */

extern int atoi(const char *);

struct MMUTarget {
    char pad[0xA4];
    int m_topLevelChoice;
    int m_prevTopLevelChoice;
    void UpdateTopLevelChoice(char *key, char *val);
    void UpdateMenuState(void);
};

void MMUTarget::UpdateTopLevelChoice(char *key, char *val)
{
    int newVal = atoi(val);
    int oldVal = m_topLevelChoice;
    m_topLevelChoice = newVal;
    m_prevTopLevelChoice = oldVal;
    UpdateMenuState();
}
