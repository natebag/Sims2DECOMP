// 0x80099834 DummyMode::DummyMode(void) (48B)
// FLAGS: -O1
// DOL: vtable at this+8 (8 bytes of base class data before vtable)
// Dead stores: sp+8=0, sp+16=2 (compiler artifacts from inlined base ctor)
// EGameState ctor inlined: m_stateId=0 + vtable; then DummyMode overrides m_stateId=2

extern int DummyMode_vtable[];
extern int EGameState_vtable[];

struct EGameState {
    int m_stateId;    // this+0
    int m_flags;      // this+4
    int* m_vtable;    // this+8
    EGameState() {
        m_vtable = (int*)EGameState_vtable;
        m_stateId = 0;
    }
};

struct DummyMode : EGameState {
    DummyMode();
};

DummyMode::DummyMode() {
    m_vtable = (int*)DummyMode_vtable;
    volatile int zero = 0;
    m_stateId = zero;
    volatile int two = 2;
    m_stateId = two;
}
