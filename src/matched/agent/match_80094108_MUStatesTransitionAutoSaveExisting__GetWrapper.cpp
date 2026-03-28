// 0x80094108 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesTransitionAutoSaveExisting {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesTransitionAutoSaveExisting::GetWrapper(void) {
    return m_owner->m_wrapper;
}
