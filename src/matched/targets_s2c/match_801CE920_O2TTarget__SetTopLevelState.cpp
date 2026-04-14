/* O2TTarget::SetTopLevelState(char *, char *) at 0x801CE920 (84B) */

int AtoI(char*);

struct O2TTarget {
    char pad_000[0x88];
    int m_topLevelState;
    int m_topLevelOldState;

    void SetTopLevelState(char* key, char* value);
    void OnStateChange(char* key, char* value);
};

void O2TTarget::SetTopLevelState(char* key, char* value) {
    int newState = AtoI(value);
    int oldState = m_topLevelState;
    m_topLevelState = newState;
    m_topLevelOldState = oldState;
    OnStateChange(key, value);
}
