typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xBC];
    float m_fDialogPosX;
public:
    void SetDialogPosX(float);
};

void DlgWrapper::SetDialogPosX(float x) {
    m_fDialogPosX = x;
}
