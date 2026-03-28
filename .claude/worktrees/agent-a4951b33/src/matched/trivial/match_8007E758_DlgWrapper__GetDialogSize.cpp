// 0x8007E758 (8 bytes)
class DlgWrapper {
public:
    int GetDialogSize();
};

int DlgWrapper::GetDialogSize() {
    return (int)((char*)this + 0xC4);
}
