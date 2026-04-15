// 0x80090FB4 LoadingScreenStateMachine::IsFadingOut (16B)
// SDA global deref, check bit 1 of field@180

struct StateMachineHolder {
    char pad[180];
    int m_flags;
};

extern StateMachineHolder* g_stateMachineHolder;  // at -32160(r13)

struct LoadingScreenStateMachine {
    int IsFadingOut();
};

int LoadingScreenStateMachine::IsFadingOut() {
    StateMachineHolder* h = g_stateMachineHolder;
    return (h->m_flags >> 1) & 1;
}
