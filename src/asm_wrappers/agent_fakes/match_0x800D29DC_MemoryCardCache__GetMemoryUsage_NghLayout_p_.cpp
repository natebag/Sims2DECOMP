/* MemoryCardCache::GetMemoryUsage(NghLayout *) at 0x800D29DC (140B) */

struct MemoryCardCache { void GetMemoryUsage(); };

__attribute__((naked))
void MemoryCardCache::GetMemoryUsage() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF61000C\n"
        ".long 0x90010024\n"
        ".long 0x7C7D1B78\n"
        ".long 0x7C9E2378\n"
        ".long 0x801D0004\n"
        ".long 0x3B600000\n"
        ".long 0x2C000000\n"
        ".long 0x41820050\n"
        ".long 0x801E000C\n"
        ".long 0x3BE00000\n"
        ".long 0x7C1B0000\n"
        ".long 0x40800040\n"
        ".long 0x3B800000\n"
        ".long 0x813D0004\n"
        ".long 0x7C1C482E\n"
        ".long 0x2C000000\n"
        ".long 0x41820018\n"
        ".long 0x7FA3EB78\n"
        ".long 0x7FC4F378\n"
        ".long 0x7FE5FB78\n"
        ".long 0x48000035\n"
        ".long 0x7F7B1A14\n"
        ".long 0x801E000C\n"
        ".long 0x3BFF0001\n"
        ".long 0x3B9C0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x4180FFCC\n"
        ".long 0x7F63DB78\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB61000C\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
