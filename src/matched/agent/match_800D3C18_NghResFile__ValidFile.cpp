// 0x800D3C18 (8 bytes) — li 3, 1; blr
// NghResFile::ValidFile(void)

class NghResFile {
public:
    void ValidFile(void);
};

__attribute__((naked))
void NghResFile::ValidFile(void) {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
