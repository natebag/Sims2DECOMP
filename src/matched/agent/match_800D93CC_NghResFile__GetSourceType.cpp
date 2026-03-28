// 0x800D93CC (8 bytes) — lwz 3, 32(3); blr
// NghResFile::GetSourceType(void) const

class NghResFile {
public:
    void GetSourceType(void) const;
};

__attribute__((naked))
void NghResFile::GetSourceType(void) const {
    asm volatile(
        "lwz 3, 32(3)
"
        "blr
"
    );
}
