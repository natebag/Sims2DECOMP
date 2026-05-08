// 0x80089A14 EGameStateMan::EGameStateMan(void) (40B)

struct EGameStateMan {
    int m_0;
    int m_4;
    int m_8;
    int m_12;
    int m_16;
    EGameStateMan();
};

EGameStateMan::EGameStateMan() {
    EGameStateMan* p = this;
    int* q = &p->m_4;
    *(volatile int*)&q[1] = 0;
    *(volatile int*)&q[0] = 0;
    *(volatile int*)&q[2] = 1;
    *(volatile int*)&p->m_0 = 0;
    *(volatile int*)&p->m_16 = 0;
}
