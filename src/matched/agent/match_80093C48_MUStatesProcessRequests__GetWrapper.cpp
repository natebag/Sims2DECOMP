// 0x80093C48 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesProcessRequests {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesProcessRequests::GetWrapper(void) {
    return m_owner->m_wrapper;
}
