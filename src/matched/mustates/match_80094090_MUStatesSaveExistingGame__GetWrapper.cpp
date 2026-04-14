// 0x80094090 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesSaveExistingGame {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesSaveExistingGame::GetWrapper(void) {
    return m_owner->m_wrapper;
}
