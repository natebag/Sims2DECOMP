// 0x8007E674 (8 bytes)
class DlgWrapper {
public:
    int GetDialogPos();
};

int DlgWrapper::GetDialogPos() {
    return (int)((char*)this + 0xBC);
}
