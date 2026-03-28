typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xBC];
    float m_fDialogPosX;
public:
    float GetDialogPosX() const;
};

float DlgWrapper::GetDialogPosX() const {
    return m_fDialogPosX;
}
