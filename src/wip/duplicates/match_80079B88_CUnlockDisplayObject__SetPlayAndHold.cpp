typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x6C];
    int m_bPlayAndHold;
public:
    void SetPlayAndHold(bool);
};

void CUnlockDisplayObject::SetPlayAndHold(bool val) {
    m_bPlayAndHold = val;
}
