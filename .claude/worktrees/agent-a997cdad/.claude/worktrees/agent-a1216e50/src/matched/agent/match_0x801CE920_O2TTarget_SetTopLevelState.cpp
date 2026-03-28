/* O2TTarget::SetTopLevelState - 0x801CE920 - 84 bytes */

extern int atoi(const char *);

struct O2TTarget {
    char pad[0x88];
    int m_topLevelState;
    int m_prevTopLevelState;
    void SetTopLevelState(char *key, char *val);
    void OnTopLevelStateChange(char *key, char *val);
};

void O2TTarget::SetTopLevelState(char *key, char *val)
{
    int newVal = atoi(val);
    int oldVal = m_topLevelState;
    m_topLevelState = newVal;
    m_prevTopLevelState = oldVal;
    OnTopLevelStateChange(key, val);
}
