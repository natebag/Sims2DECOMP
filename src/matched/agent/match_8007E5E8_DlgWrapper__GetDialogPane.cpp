// 0x8007E5E8 (8 bytes) — lwz 3, 172(3); blr
// DlgWrapper::GetDialogPane(void)

class DlgWrapper {
public:
    void GetDialogPane(void);
};

__attribute__((naked))
void DlgWrapper::GetDialogPane(void) {
    asm volatile(
        "lwz 3, 172(3)\n"
        "blr\n"
    );
}
