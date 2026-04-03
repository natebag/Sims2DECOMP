typedef unsigned char u8;

struct EVec3 {
    float x, y, z;
};

class SAnimator2 {
    u8 _pad0[0x1C];
    EVec3 m_vPos;
public:
    EVec3 *GetPos();
};

EVec3 *SAnimator2::GetPos() {
    return &m_vPos;
}
