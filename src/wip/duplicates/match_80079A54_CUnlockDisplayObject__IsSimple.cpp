typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x80];
    int m_bSimple;
public:
    int IsSimple();
};

int CUnlockDisplayObject::IsSimple() {
    return m_bSimple;
}
