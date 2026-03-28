// 0x800D3D60 (8 bytes) — li 3, 0; blr
// NghResFile::FindUniqueID(int)

class NghResFile {
public:
    void FindUniqueID(int);
};

__attribute__((naked))
void NghResFile::FindUniqueID(int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
