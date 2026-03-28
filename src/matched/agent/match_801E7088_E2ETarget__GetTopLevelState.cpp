class E2ETarget {
public:
    char pad[0xD8];
    int m_topLevelState;
    int GetTopLevelState(void);
};

int E2ETarget::GetTopLevelState(void) {
    return m_topLevelState;
}
