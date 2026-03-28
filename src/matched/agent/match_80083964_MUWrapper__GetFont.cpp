// 0x80083964 (8 bytes) — lwz 3, 164(3); blr
// MUWrapper::GetFont(void)

class MUWrapper {
public:
    void GetFont(void);
};

__attribute__((naked))
void MUWrapper::GetFont(void) {
    asm volatile(
        "lwz 3, 164(3)
"
        "blr
"
    );
}
