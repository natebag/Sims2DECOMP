// 0x800D8EE0 (8 bytes) — stw 4, 396(3); blr
// NghResFile::SetStoreChecksum(bool)

class NghResFile {
public:
    void SetStoreChecksum(bool);
};

__attribute__((naked))
void NghResFile::SetStoreChecksum(bool) {
    asm volatile(
        "stw 4, 396(3)
"
        "blr
"
    );
}
