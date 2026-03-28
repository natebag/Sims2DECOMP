// 0x8007E768 (8 bytes) — lfs 1, 200(3); blr
// DlgWrapper::GetDialogSizeY(void) const

class DlgWrapper {
public:
    void GetDialogSizeY(void) const;
};

__attribute__((naked))
void DlgWrapper::GetDialogSizeY(void) const {
    asm volatile(
        "lfs 1, 200(3)\n"
        "blr\n"
    );
}
