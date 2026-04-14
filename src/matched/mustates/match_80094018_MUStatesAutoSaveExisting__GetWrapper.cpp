// 0x80094018 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesAutoSaveExisting {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesAutoSaveExisting::GetWrapper(void) {
    return m_owner->m_wrapper;
}
