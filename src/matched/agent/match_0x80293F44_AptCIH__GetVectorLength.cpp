// FLAGS: -fno-elide-constructors -fno-schedule-insns2 -mno-fused-madd
extern float gAptZeroF[];
float sqrtf(float);

struct AptMtx {
    float m_a;
    float m_b;
    float m_c;
};

struct CIH_VL {
    static float GetVectorLength(AptMtx *m);
};

float CIH_VL::GetVectorLength(AptMtx *m) {
    float zero = gAptZeroF[0];
    if (m->m_b != zero || m->m_c != zero) {
        return sqrtf(m->m_a + m->m_b * m->m_b);
    }
    return m->m_a;
}
