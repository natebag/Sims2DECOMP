typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xC0];
    float m_fDialogPosY;
public:
    void SetDialogPosY(float);
};

void DlgWrapper::SetDialogPosY(float y) {
    m_fDialogPosY = y;
}
