typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[4];
    int m_nType;
public:
    int GetType();
};

int CUnlockDisplayObject::GetType() {
    return m_nType;
}
