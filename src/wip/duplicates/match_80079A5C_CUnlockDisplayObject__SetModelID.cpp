typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x2C];
    unsigned int m_nModelID;
public:
    void SetModelID(unsigned int);
};

void CUnlockDisplayObject::SetModelID(unsigned int id) {
    m_nModelID = id;
}
