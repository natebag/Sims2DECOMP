// 0x8009B258 (44B) UrbzModeNewGameState::Reset(void)

struct Something;
extern char g_something[16];
extern void DoSomething(Something* s);

struct UrbzModeNewGameState {
    char pad[12];
    int m_field_12;
    void Reset();
};

void UrbzModeNewGameState::Reset() {
    m_field_12 = 0;
    DoSomething(*(Something**)g_something);
}
