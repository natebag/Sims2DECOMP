// 0x8007E67C (8 bytes) — lfs 1, 188(3); blr
// DlgWrapper::GetDialogPosX(void) const

class DlgWrapper {
public:
    void GetDialogPosX(void) const;
};

__attribute__((naked))
void DlgWrapper::GetDialogPosX(void) const {
    asm volatile(
        "lfs 1, 188(3)
"
        "blr
"
    );
}
