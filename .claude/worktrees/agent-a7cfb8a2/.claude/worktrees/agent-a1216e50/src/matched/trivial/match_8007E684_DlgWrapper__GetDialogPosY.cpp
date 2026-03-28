// 0x8007E684 (8 bytes)
class DlgWrapper {
public:
    float GetDialogPosY();
};

float DlgWrapper::GetDialogPosY() {
    return *(float*)((char*)this + 0xC0);
}
