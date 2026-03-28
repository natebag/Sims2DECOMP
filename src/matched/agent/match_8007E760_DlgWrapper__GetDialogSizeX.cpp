// 0x8007E760 (8 bytes) — lfs 1, 196(3); blr
// DlgWrapper::GetDialogSizeX(void) const

class DlgWrapper {
public:
    void GetDialogSizeX(void) const;
};

__attribute__((naked))
void DlgWrapper::GetDialogSizeX(void) const {
    asm volatile(
        "lfs 1, 196(3)\n"
        "blr\n"
    );
}
