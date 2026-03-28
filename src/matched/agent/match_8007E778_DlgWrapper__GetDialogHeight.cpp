typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xC8];
    float m_fDialogSizeY;
public:
    float GetDialogHeight() const;
};

float DlgWrapper::GetDialogHeight() const {
    return m_fDialogSizeY;
}
