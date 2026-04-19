// FLAGS: -fno-unroll-loops
// 0x800961BC (56 bytes)

struct StateEntry {
    int m_id;
};

struct StateMachine {
    char pad[0x2C];
    StateEntry** m_begin;  // offset 0x2C
    StateEntry** m_end;    // offset 0x30

    StateEntry* FindStateById(int id);
};

StateEntry* StateMachine::FindStateById(int id) {
    StateEntry** end = m_end;
    StateEntry** begin = m_begin;
    if (begin == end) return 0;
    do {
        StateEntry* e = *begin;
        if (e->m_id == id) return e;
        ++begin;
    } while (begin != end);
    return 0;
}
