typedef unsigned char u8;

class CUnlockDisplay {
    u8 _pad0[0x458];
    int m_bHidden;
public:
    void UnHide();
};

void CUnlockDisplay::UnHide() {
    m_bHidden = 0;
}
