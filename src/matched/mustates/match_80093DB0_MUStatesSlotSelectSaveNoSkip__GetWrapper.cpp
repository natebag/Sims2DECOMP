// 0x80093DB0 (12 bytes)
class MUWrapper;

class MUStateMachine {
public:
    char pad[152];
    MUWrapper *m_wrapper;
};

class MUStatesSlotSelectSaveNoSkip {
public:
    int pad[2];
    MUStateMachine *m_owner;

    MUWrapper *GetWrapper(void);
};

MUWrapper *MUStatesSlotSelectSaveNoSkip::GetWrapper(void) {
    return m_owner->m_wrapper;
}
