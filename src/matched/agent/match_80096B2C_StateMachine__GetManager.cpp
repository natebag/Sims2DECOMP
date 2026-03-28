// 0x80096B2C (8 bytes)
class StateMachine {
public:
    char pad[32];
    void *m_manager;

    void *GetManager(void) const;
};

void *StateMachine::GetManager(void) const {
    return m_manager;
}
