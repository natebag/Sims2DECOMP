// 0x80090E88 (12 bytes)
class LoadingScreenStateMachine {
public:
    char pad[180];
    int m_faderRunning;

    void FaderStop(void);
};

void LoadingScreenStateMachine::FaderStop(void) {
    m_faderRunning = 0;
}
