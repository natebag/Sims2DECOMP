// 0x800961BC (56 bytes)
struct StateMachineState {
    int m_id;  // 0x00
};

struct StateMachine {
    char pad[0x2C];               // 0x00-0x2B
    StateMachineState** m_begin;  // 0x2C (44)
    StateMachineState** m_end;    // 0x30 (48)

    StateMachineState* FindStateById(int id);
};

StateMachineState* StateMachine::FindStateById(int id) {
    StateMachineState** end = m_end;
    StateMachineState** cur = m_begin;
    if (cur == end) goto done;
    {
        int count = id;  // save id in r11
        do {
            StateMachineState* s = *cur;
            if (s->m_id == count) return s;
            ++cur;
        } while (cur != end);
    }
done:
    return 0;
}
