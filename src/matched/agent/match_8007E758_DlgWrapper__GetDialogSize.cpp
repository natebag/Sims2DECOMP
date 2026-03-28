// 0x8007E758 (8 bytes) — addi 3, 3, 196; blr
// DlgWrapper::GetDialogSize(void)

class DlgWrapper {
public:
    void GetDialogSize(void);
};

__attribute__((naked))
void DlgWrapper::GetDialogSize(void) {
    asm volatile(
        "addi 3, 3, 196
"
        "blr
"
    );
}
