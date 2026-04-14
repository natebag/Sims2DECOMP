/* EParticleObj::EParticleObj(void) at 0x8004C130 (32B) */

struct EParticleObj {
    int m_field_0;
    int m_field_4;
    int m_field_8;
    int m_field_C;

    EParticleObj(void);
};

EParticleObj::EParticleObj(void) {
    m_field_4 = 0;
    m_field_0 = 0;
    m_field_8 = 1;
    m_field_C = 0;
}
