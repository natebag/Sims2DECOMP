typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x28];
    float m_fRadius;
public:
    float GetRadius();
};

float CUnlockDisplayObject::GetRadius() {
    return m_fRadius;
}
