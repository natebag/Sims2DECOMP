// 0x8007E66C (8 bytes) — stfs 1, 192(3); blr
// DlgWrapper::SetDialogPosY(float)

class DlgWrapper {
public:
    void SetDialogPosY(float);
};

__attribute__((naked))
void DlgWrapper::SetDialogPosY(float) {
    asm volatile(
        "stfs 1, 192(3)\n"
        "blr\n"
    );
}
