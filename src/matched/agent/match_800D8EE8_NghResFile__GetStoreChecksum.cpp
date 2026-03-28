// 0x800D8EE8 (8 bytes) — lwz 3, 396(3); blr
// NghResFile::GetStoreChecksum(void)

class NghResFile {
public:
    void GetStoreChecksum(void);
};

__attribute__((naked))
void NghResFile::GetStoreChecksum(void) {
    asm volatile(
        "lwz 3, 396(3)
"
        "blr
"
    );
}
