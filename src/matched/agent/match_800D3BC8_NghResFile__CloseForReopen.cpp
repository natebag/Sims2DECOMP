// 0x800D3BC8 (8 bytes) — li 3, 0; blr
// NghResFile::CloseForReopen(void)

class NghResFile {
public:
    void CloseForReopen(void);
};

__attribute__((naked))
void NghResFile::CloseForReopen(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
