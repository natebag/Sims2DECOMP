// 0x8012B1B8 cXPersonImpl::IsSleeping (28B)

extern float sSleepThreshold[4];

struct cXPersonImpl_IsSlp {
    char _pad[0xa8];
    float m_motives[16];
    int IsSleeping();
};

int cXPersonImpl_IsSlp::IsSleeping() {
    return m_motives[11] < sSleepThreshold[0];
}
