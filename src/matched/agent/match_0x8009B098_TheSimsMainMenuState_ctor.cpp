// 0x8009B098 (60B) TheSimsMainMenuState::TheSimsMainMenuState(int)
// State ctor sister; vtable at 0x8045E268; ALSO stores `this` to SDA singleton at -24624(r13).

extern char kMainMenuStateData[];     // 0x8045E268

class TheSimsMainMenuState;
extern TheSimsMainMenuState* g_mainMenuState;   // SDA -24624(r13)

class TheSimsMainMenuState {
public:
    int m_field0;        // +0
    int m_field4;        // +4
    int m_field8;        // +8
    int m_field12;       // +12
    int m_field16;       // +16
    int m_field20;       // +20
    char* m_field24;     // +24

    TheSimsMainMenuState(int x);
};

TheSimsMainMenuState::TheSimsMainMenuState(int x)
{
    m_field0 = x;
    m_field4 = -1;
    m_field8 = 0;
    m_field12 = -1;
    m_field16 = 0;
    m_field20 = 1;
    m_field24 = kMainMenuStateData;
    g_mainMenuState = this;
}
