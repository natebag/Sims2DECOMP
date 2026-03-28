// 0x800D3C28 (8 bytes) — li 3, 0; blr
// NghResFile::GetIndType(short)

class NghResFile {
public:
    void GetIndType(short);
};

__attribute__((naked))
void NghResFile::GetIndType(short) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
