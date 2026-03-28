// 0x8007E664 (8 bytes) — stfs 1, 188(3); blr
// DlgWrapper::SetDialogPosX(float)

class DlgWrapper {
public:
    void SetDialogPosX(float);
};

__attribute__((naked))
void DlgWrapper::SetDialogPosX(float) {
    asm volatile(
        "stfs 1, 188(3)\n"
        "blr\n"
    );
}
