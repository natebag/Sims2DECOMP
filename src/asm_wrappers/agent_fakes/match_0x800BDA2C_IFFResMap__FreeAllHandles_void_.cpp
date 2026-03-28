/* IFFResMap::FreeAllHandles(void) at 0x800BDA2C (156B) */

struct IFFResMap { void FreeAllHandles(); };

__attribute__((naked))
void IFFResMap::FreeAllHandles() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF61000C\n"
        ".long 0x90010024\n"
        ".long 0x7C7B1B78\n"
        ".long 0x83BB0000\n"
        ".long 0x801B0004\n"
        ".long 0x7C1D0000\n"
        ".long 0x41820068\n"
        ".long 0x83DD0000\n"
        ".long 0x3B9D0018\n"
        ".long 0x801D0004\n"
        ".long 0x7C1E0000\n"
        ".long 0x41820044\n"
        ".long 0x83FE000C\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820028\n"
        ".long 0x801F0008\n"
        ".long 0x2C000000\n"
        ".long 0x41820010\n"
        ".long 0x48212485\n"
        ".long 0x809F0004\n"
        ".long 0x482132F5\n"
        ".long 0x48212479\n"
        ".long 0x7FE4FB78\n"
        ".long 0x482132E9\n"
        ".long 0x801D0004\n"
        ".long 0x3BDE0058\n"
        ".long 0x7C1E0000\n"
        ".long 0x4082FFC4\n"
        ".long 0x801B0004\n"
        ".long 0x7F9DE378\n"
        ".long 0x7C1D0000\n"
        ".long 0x4082FFA0\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB61000C\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
