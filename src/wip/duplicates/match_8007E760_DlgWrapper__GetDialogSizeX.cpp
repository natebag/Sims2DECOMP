// 0x8007E760 (8 bytes)
class DlgWrapper {
public:
    float GetDialogSizeX();
};

float DlgWrapper::GetDialogSizeX() {
    return *(float*)((char*)this + 0xC4);
}
