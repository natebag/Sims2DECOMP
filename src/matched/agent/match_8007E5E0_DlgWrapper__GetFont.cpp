typedef unsigned char u8;
class ERFont;

class DlgWrapper {
    u8 _pad0[0xA8];
    ERFont *m_pFont;
public:
    ERFont *GetFont();
};

ERFont *DlgWrapper::GetFont() {
    return m_pFont;
}
