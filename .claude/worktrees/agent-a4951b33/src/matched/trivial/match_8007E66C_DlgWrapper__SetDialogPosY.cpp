// 0x8007E66C (8 bytes)
class DlgWrapper {
public:
    void SetDialogPosY(float p);
};

void DlgWrapper::SetDialogPosY(float p) {
    *(float*)((char*)this + 0xC0) = p;
}
