// 0x800D3CC8 (8 bytes) — li 3, 0; blr
// NghResFile::GetByName(int, StringBuffer &, void (*)(void *, int))

class NghResFile {
public:
    void GetByName(int, StringBuffer &, void (*)(void *, int));
};

__attribute__((naked))
void NghResFile::GetByName(int, StringBuffer &, void (*)(void *, int)) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
