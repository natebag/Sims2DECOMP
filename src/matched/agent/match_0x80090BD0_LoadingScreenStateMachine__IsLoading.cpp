// 0x80090BD0 (76B) LoadingScreenStateMachine::IsLoading(void)
// stmw r30,8: r31=self (survives call), r30=result (bool accumulator).
// goto-shared-label: bne(stateId!=0) shares set_true with fall-through(field160!=0).

struct StateMachine_IL {
    char _pad[0xa0];
    int m_field160;
    int GetCurStateId() const;
};

struct LoadingScreenStateMachine_IL : public StateMachine_IL {
    bool IsLoading();
};

bool LoadingScreenStateMachine_IL::IsLoading() {
    bool result = false;
    if (GetCurStateId() != 0) goto set_true;
    if (m_field160 == 0) goto done;
set_true:
    result = true;
done:
    return result;
}
