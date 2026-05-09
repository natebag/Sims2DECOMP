// 0x8009AFB8 (60B) TheSimsSimsIntroMovieState::TheSimsSimsIntroMovieState(int)
// State ctor: inits 8 fields, vtable-like ptr at +24 to 0x8045E2F8.

extern char kIntroMovieStateData[];   // 0x8045E2F8

class TheSimsSimsIntroMovieState {
public:
    int m_field0;        // +0
    int m_field4;        // +4
    int m_field8;        // +8
    int m_field12;       // +12
    int m_field16;       // +16
    int m_field20;       // +20
    char* m_field24;     // +24
    int _pad28[2];       // +28..+32
    int m_field36;       // +36

    TheSimsSimsIntroMovieState(int x);
};

TheSimsSimsIntroMovieState::TheSimsSimsIntroMovieState(int x)
{
    m_field0 = x;
    m_field4 = -1;
    m_field8 = 0;
    m_field12 = -1;
    m_field16 = 0;
    m_field20 = 1;
    m_field24 = kIntroMovieStateData;
    m_field36 = 0;
}
