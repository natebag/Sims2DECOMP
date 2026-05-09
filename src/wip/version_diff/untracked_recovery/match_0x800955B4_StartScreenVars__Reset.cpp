extern float g_a __attribute__((section(".data")));
extern float g_b __attribute__((section(".data")));
extern float g_c __attribute__((section(".data")));
extern float g_d __attribute__((section(".data")));
extern float g_e __attribute__((section(".data")));

class StartScreenVars {
public:
    float m_00;
    float m_04;
    float m_08;
    int m_0C;
    int m_10;
    int m_14;
    float m_18;
    float m_1C;
    char pad[4];
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    float m_34;
    
    void Reset();
};

void StartScreenVars::Reset() {
    float tmp[2];
    tmp[0] = g_a;
    tmp[1] = g_b;
    m_34 = g_c;
    m_04 = g_d;
    m_0C = 1;
    m_10 = *(int*)&tmp[0];
    m_14 = *(int*)&tmp[1];
    m_18 = g_e;
    m_00 = g_c;
    m_08 = g_c;
    m_1C = g_c;
    m_24 = 0;
    m_28 = 0;
    m_2C = 0;
    m_30 = 0;
}
