// 0x8007E770 (8 bytes)
class DlgWrapper {
public:
    float GetDialogWidth();
};

float DlgWrapper::GetDialogWidth() {
    return *(float*)((char*)this + 0xC4);
}
