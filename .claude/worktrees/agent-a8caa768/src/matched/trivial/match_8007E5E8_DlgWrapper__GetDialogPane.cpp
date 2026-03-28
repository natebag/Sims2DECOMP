// 0x8007E5E8 (8 bytes)
class DlgWrapper {
public:
    int GetDialogPane();
};

int DlgWrapper::GetDialogPane() {
    return *(int*)((char*)this + 0xAC);
}
