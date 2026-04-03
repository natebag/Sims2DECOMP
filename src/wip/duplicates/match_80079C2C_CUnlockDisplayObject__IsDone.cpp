typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x78];
    int m_bDone;
public:
    int IsDone();
};

int CUnlockDisplayObject::IsDone() {
    return m_bDone;
}
