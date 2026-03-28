// 0x800D3BE4 (8 bytes) — li 3, 0; blr
// NghResFile::Writable(void)

class NghResFile {
public:
    void Writable(void);
};

__attribute__((naked))
void NghResFile::Writable(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
