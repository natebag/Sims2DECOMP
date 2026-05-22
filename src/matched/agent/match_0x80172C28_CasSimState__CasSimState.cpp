// 0x80172C28 CasSimState::CasSimState() (80B)

class CasSimDescriptionS2C {
public:
    char pad[0x124];
    CasSimDescriptionS2C();
};

extern int CasSimState_vtable[];  // at 0x80466248

class CasSimState {
public:
    int m_0;
    int* m_4;
    CasSimDescriptionS2C m_8;
    CasSimDescriptionS2C m_12C;
    CasSimState();
};

CasSimState::CasSimState() : m_0(0), m_4(CasSimState_vtable) {}
