// 0x8007E674 (8 bytes) — addi 3, 3, 188; blr
// DlgWrapper::GetDialogPos(void)

class DlgWrapper {
public:
    void GetDialogPos(void);
};

__attribute__((naked))
void DlgWrapper::GetDialogPos(void) {
    asm volatile(
        "addi 3, 3, 188\n"
        "blr\n"
    );
}
