typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x38];
    unsigned int m_nAnimationLoops;
public:
    void SetAnimationLoops(unsigned int);
};

void CUnlockDisplayObject::SetAnimationLoops(unsigned int loops) {
    m_nAnimationLoops = loops;
}
