// 0x80096B50 (12 bytes)
class StateMachine {
public:
    char pad[148];
    int m_enabled;

    void Enable(void);
};

void StateMachine::Enable(void) {
    m_enabled = 1;
}
