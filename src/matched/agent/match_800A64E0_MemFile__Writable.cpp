// 0x800A64E0 (8 bytes) — lwz 3, 268(3); blr
// MemFile::Writable(void)

class MemFile {
public:
    void Writable(void);
};

__attribute__((naked))
void MemFile::Writable(void) {
    asm volatile(
        "lwz 3, 268(3)
"
        "blr
"
    );
}
