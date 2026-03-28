typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xC4];
    float m_fDialogSizeX;
public:
    float GetDialogWidth() const;
};

float DlgWrapper::GetDialogWidth() const {
    return m_fDialogSizeX;
}
