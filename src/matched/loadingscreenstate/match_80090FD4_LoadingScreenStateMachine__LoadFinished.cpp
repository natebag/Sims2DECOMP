// 0x80090FD4 (12 bytes)
class LoadingScreenStateMachine {
public:
    char pad[164];
    int m_loadComplete;

    void LoadFinished(void);
};

void LoadingScreenStateMachine::LoadFinished(void) {
    m_loadComplete = 1;
}
