typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xC0];
    float m_fDialogPosY;
public:
    float GetDialogPosY() const;
};

float DlgWrapper::GetDialogPosY() const {
    return m_fDialogPosY;
}
