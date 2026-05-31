// 0x80095E0C StateMachine::GetCurStateId(void) const (28 B)

struct State {
    int m_id;
};

struct StateMachine {
    char pad_0000[0x3c];
    State* m_curState;

    int GetCurStateId() const;
};

int StateMachine::GetCurStateId() const {
    State* s = m_curState;
    if (s != 0) {
        return s->m_id;
    }
    return -1;
}
