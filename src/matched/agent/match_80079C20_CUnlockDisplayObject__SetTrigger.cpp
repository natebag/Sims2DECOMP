typedef unsigned char u8;

class CUnlockDisplayObject {
    u8 _pad0[0x70];
    int m_bTriggered;
public:
    void SetTrigger();
};

void CUnlockDisplayObject::SetTrigger() {
    m_bTriggered = 1;
}
