// 0x8022E67C EIStaticSubModel::GetBoundSphere(EBoundSphere&) (40B)

struct Vec3 {
    float x, y, z;
};

struct EBoundSphere {
    Vec3 pos;
    float r;
};

class EIStaticSubModel {
    char m_pad[0x80];
    EBoundSphere m_bound;
public:
    void GetBoundSphere(EBoundSphere& out) const;
};

void EIStaticSubModel::GetBoundSphere(EBoundSphere& out) const {
    const EBoundSphere* p = &m_bound;
    out.pos = p->pos;
    out.r = p->r;
}
