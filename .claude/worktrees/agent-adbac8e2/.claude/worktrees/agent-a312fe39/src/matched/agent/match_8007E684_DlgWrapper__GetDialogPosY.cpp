// 0x8007E684 (8 bytes) — lfs 1, 192(3); blr
// DlgWrapper::GetDialogPosY(void) const

class DlgWrapper {
public:
    void GetDialogPosY(void) const;
};

__attribute__((naked))
void DlgWrapper::GetDialogPosY(void) const {
    asm volatile(
        "lfs 1, 192(3)\n"
        "blr\n"
    );
}
