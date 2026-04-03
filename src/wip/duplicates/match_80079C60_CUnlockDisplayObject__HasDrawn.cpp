typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x7C];
    int m_bHasDrawn;
public:
    int HasDrawn();
};

int CUnlockDisplayObject::HasDrawn() {
    return m_bHasDrawn;
}
