// 0x800D3BB8 (8 bytes) — li 3, 0; blr
// NghResFile::Delete(StringBuffer &)

class NghResFile {
public:
    void Delete(StringBuffer &);
};

__attribute__((naked))
void NghResFile::Delete(StringBuffer &) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
