// 0x80093F18 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesAutoSaveNew {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesAutoSaveNew::GetWrapper(void) {
    return m_owner->m_wrapper;
}
