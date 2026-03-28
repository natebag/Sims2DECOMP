// 0x8007E5E0 (8 bytes) — lwz 3, 168(3); blr
// DlgWrapper::GetFont(void)

class DlgWrapper {
public:
    void GetFont(void);
};

__attribute__((naked))
void DlgWrapper::GetFont(void) {
    asm volatile(
        "lwz 3, 168(3)\n"
        "blr\n"
    );
}
