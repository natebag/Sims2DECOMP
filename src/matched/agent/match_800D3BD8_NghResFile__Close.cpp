// 0x800D3BD8 (8 bytes) — li 3, 0; blr
// NghResFile::Close(void)

class NghResFile {
public:
    void Close(void);
};

__attribute__((naked))
void NghResFile::Close(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
