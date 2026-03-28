// 0x8007E768 (8 bytes)
class DlgWrapper {
public:
    float GetDialogSizeY();
};

float DlgWrapper::GetDialogSizeY() {
    return *(float*)((char*)this + 0xC8);
}
