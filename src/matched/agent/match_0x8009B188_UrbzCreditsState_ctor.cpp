// 0x8009B188 (56B) UrbzCreditsState::UrbzCreditsState(int)
// State ctor sister to TheSimsSimsIntroMovieState; vtable at 0x8045E220, no +36 store.

extern char kCreditsStateData[];   // 0x8045E220

class UrbzCreditsState {
public:
    int m_field0;        // +0
    int m_field4;        // +4
    int m_field8;        // +8
    int m_field12;       // +12
    int m_field16;       // +16
    int m_field20;       // +20
    char* m_field24;     // +24

    UrbzCreditsState(int x);
};

UrbzCreditsState::UrbzCreditsState(int x)
{
    m_field0 = x;
    m_field4 = -1;
    m_field8 = 0;
    m_field12 = -1;
    m_field16 = 0;
    m_field20 = 1;
    m_field24 = kCreditsStateData;
}
