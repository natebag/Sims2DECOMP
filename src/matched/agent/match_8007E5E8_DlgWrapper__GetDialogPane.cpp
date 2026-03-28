typedef unsigned char u8;
class DialogPane;

class DlgWrapper {
    u8 _pad0[0xAC];
    DialogPane *m_pDialogPane;
public:
    DialogPane *GetDialogPane();
};

DialogPane *DlgWrapper::GetDialogPane() {
    return m_pDialogPane;
}
