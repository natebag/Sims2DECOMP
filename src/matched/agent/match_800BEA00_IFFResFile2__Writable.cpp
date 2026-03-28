// 0x800BEA00 (8 bytes) — lwz 3, 284(3); blr
// IFFResFile2::Writable(void)

class IFFResFile2 {
public:
    void Writable(void);
};

__attribute__((naked))
void IFFResFile2::Writable(void) {
    asm volatile(
        "lwz 3, 284(3)\n"
        "blr\n"
    );
}
