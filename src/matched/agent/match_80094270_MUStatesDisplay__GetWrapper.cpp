// 0x80094270 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesDisplay {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesDisplay::GetWrapper(void) {
    return m_owner->m_wrapper;
}
