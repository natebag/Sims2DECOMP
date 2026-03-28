/* MemoryCardCache::PutConfig(char *, unsigned int) at 0x800D37C8 (152B) */

struct MemoryCardCache { void PutConfig(); };

__attribute__((naked))
void MemoryCardCache::PutConfig() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9D2378\n"
        ".long 0x801F0010\n"
        ".long 0x7CBE2B78\n"
        ".long 0x2C000000\n"
        ".long 0x4082000C\n"
        ".long 0x38600001\n"
        ".long 0x48000058\n"
        ".long 0x801F0000\n"
        ".long 0x2C000000\n"
        ".long 0x4082002C\n"
        ".long 0x481FC6FD\n"
        ".long 0x38802000\n"
        ".long 0x38A00040\n"
        ".long 0x38C00000\n"
        ".long 0x38E00000\n"
        ".long 0x481FD359\n"
        ".long 0x2C030000\n"
        ".long 0x907F0000\n"
        ".long 0x38600002\n"
        ".long 0x41820024\n"
        ".long 0x807F0000\n"
        ".long 0x7FA4EB78\n"
        ".long 0x7FC5F378\n"
        ".long 0x4CC63182\n"
        ".long 0x4816FC19\n"
        ".long 0x38000001\n"
        ".long 0x38600000\n"
        ".long 0x901F000C\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
