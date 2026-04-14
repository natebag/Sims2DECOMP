// 0x80090E0C (12 bytes)
class LoadingScreenStateMachine {
public:
    char pad[160];
    int m_loadStatus;

    void LoadStarted(void);
};

void LoadingScreenStateMachine::LoadStarted(void) {
    m_loadStatus = 0;
}
