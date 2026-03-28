// 0x800D3BC0 (8 bytes) — li 3, 0; blr
// NghResFile::Open(StringBuffer &)

class NghResFile {
public:
    void Open(StringBuffer &);
};

__attribute__((naked))
void NghResFile::Open(StringBuffer &) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
