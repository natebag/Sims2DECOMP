/* EGameStateMan::AddState(EGameState *) at 0x80089B30 (56B) */

struct EGameState_AS {
    int m_pad0;
    void* m_manager;
};

struct SomeList_AS {
    void PushBack(EGameState_AS* s);
};

struct EGameStateMan_AS {
    int m_pad0;
    SomeList_AS m_list;
    void AddState(EGameState_AS* state);
};

void EGameStateMan_AS::AddState(EGameState_AS* state) {
    m_list.PushBack(state);
    state->m_manager = this;
}
