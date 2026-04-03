// 0x8007E67C (8 bytes)
class DlgWrapper {
public:
    float GetDialogPosX();
};

float DlgWrapper::GetDialogPosX() {
    return *(float*)((char*)this + 0xBC);
}
