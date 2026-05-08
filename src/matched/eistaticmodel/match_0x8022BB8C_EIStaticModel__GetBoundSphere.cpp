// 0x8022BB8C EIStaticModel::GetBoundSphere(EBoundSphere&) (40B)

struct Vec3 {
    float x, y, z;
};

struct EBoundSphere {
    Vec3 pos;
    float r;
};

class EIStaticModel {
    char m_pad[0x100];
    EBoundSphere m_bound;
public:
    void GetBoundSphere(EBoundSphere& out) const;
};

void EIStaticModel::GetBoundSphere(EBoundSphere& out) const {
    const EBoundSphere* p = &m_bound;
    out.pos = p->pos;
    out.r = p->r;
}
