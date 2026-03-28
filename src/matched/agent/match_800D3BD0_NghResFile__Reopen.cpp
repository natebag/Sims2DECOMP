// 0x800D3BD0 (8 bytes) — li 3, 0; blr
// NghResFile::Reopen(void)

class NghResFile {
public:
    void Reopen(void);
};

__attribute__((naked))
void NghResFile::Reopen(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
