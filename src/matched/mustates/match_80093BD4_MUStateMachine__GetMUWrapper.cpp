// 0x80093BD4 (8 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;

    MUWrapper *GetMUWrapper(void);
};

MUWrapper *MUStateMachine::GetMUWrapper(void) {
    return m_wrapper;
}
