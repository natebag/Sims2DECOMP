// 0x80096B68 (12 bytes)
class StateMachine {
public:
    char pad[36];
    int m_pauseUpdate;

    void PauseUpdate(void);
};

void StateMachine::PauseUpdate(void) {
    m_pauseUpdate = 1;
}
