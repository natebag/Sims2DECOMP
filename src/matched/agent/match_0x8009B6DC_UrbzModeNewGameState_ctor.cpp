// 0x8009B6DC (56B) UrbzModeNewGameState::UrbzModeNewGameState(int)
// State ctor sister to UrbzCreditsState; vtable at 0x8045E4A8, no +36 store.

extern char kNewGameStateData[];   // 0x8045E4A8

class UrbzModeNewGameState {
public:
    int m_field0;        // +0
    int m_field4;        // +4
    int m_field8;        // +8
    int m_field12;       // +12
    int m_field16;       // +16
    int m_field20;       // +20
    char* m_field24;     // +24

    UrbzModeNewGameState(int x);
};

UrbzModeNewGameState::UrbzModeNewGameState(int x)
{
    m_field0 = x;
    m_field4 = -1;
    m_field8 = 0;
    m_field12 = -1;
    m_field16 = 0;
    m_field20 = 1;
    m_field24 = kNewGameStateData;
}
