// 0x8007E664 (8 bytes)
class DlgWrapper {
public:
    void SetDialogPosX(float p);
};

void DlgWrapper::SetDialogPosX(float p) {
    *(float*)((char*)this + 0xBC) = p;
}
