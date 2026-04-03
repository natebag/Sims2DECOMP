typedef unsigned char u8;

struct EVec2 {
    float x, y;
};

class DlgWrapper {
    u8 _pad0[0xBC];
    EVec2 m_vDialogPos;
public:
    EVec2 *GetDialogPos();
};

EVec2 *DlgWrapper::GetDialogPos() {
    return &m_vDialogPos;
}
