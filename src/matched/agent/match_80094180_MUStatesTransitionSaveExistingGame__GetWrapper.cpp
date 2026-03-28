// 0x80094180 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesTransitionSaveExistingGame {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesTransitionSaveExistingGame::GetWrapper(void) {
    return m_owner->m_wrapper;
}
