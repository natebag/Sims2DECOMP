// 0x8007E778 (8 bytes)
class DlgWrapper {
public:
    float GetDialogHeight();
};

float DlgWrapper::GetDialogHeight() {
    return *(float*)((char*)this + 0xC8);
}
