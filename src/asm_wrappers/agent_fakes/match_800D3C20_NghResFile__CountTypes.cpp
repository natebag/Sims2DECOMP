// 0x800D3C20 (8 bytes) — li 3, 0; blr
// NghResFile::CountTypes(void)

class NghResFile {
public:
    void CountTypes(void);
};

__attribute__((naked))
void NghResFile::CountTypes(void) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
