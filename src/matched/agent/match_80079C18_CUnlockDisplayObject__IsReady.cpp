typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x74];
    int m_bReady;
public:
    int IsReady();
};

int CUnlockDisplayObject::IsReady() {
    return m_bReady;
}
