typedef unsigned char u8;

class DlgWrapper {
    u8 _pad0[0xB4];
    int m_bAptDrawable;
public:
    int IsAptDrawable();
};

int DlgWrapper::IsAptDrawable() {
    return m_bAptDrawable;
}
