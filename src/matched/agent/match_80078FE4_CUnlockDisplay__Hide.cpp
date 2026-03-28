typedef unsigned char u8;

class CUnlockDisplay {
    u8 _pad0[0x458];
    int m_bHidden;
public:
    void Hide();
};

void CUnlockDisplay::Hide() {
    m_bHidden = 1;
}
