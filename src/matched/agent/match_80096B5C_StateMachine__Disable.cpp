// 0x80096B5C (12 bytes)
class StateMachine {
public:
    char pad[148];
    int m_enabled;

    void Disable(void);
};

void StateMachine::Disable(void) {
    m_enabled = 0;
}
