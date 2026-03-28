typedef unsigned char u8;

struct EVec2 {
    float x, y;
};

class DlgWrapper {
    u8 _pad0[0xC4];
    EVec2 m_vDialogSize;
public:
    EVec2 *GetDialogSize();
};

EVec2 *DlgWrapper::GetDialogSize() {
    return &m_vDialogSize;
}
