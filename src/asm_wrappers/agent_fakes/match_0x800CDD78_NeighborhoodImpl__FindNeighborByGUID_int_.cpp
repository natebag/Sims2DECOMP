/* NeighborhoodImpl::FindNeighborByGUID(int) at 0x800CDD78 (136B) */

struct NeighborhoodImpl { void FindNeighborByGUID(); };

__attribute__((naked))
void NeighborhoodImpl::FindNeighborByGUID() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810008\n"
        ".long 0x9001001C\n"
        ".long 0x7C9C2379\n"
        ".long 0x4082000C\n"
        ".long 0x38600000\n"
        ".long 0x48000058\n"
        ".long 0x39230074\n"
        ".long 0x83E30074\n"
        ".long 0x80090004\n"
        ".long 0x7D3D4B78\n"
        ".long 0x3BC00000\n"
        ".long 0x7C1F0000\n"
        ".long 0x41820038\n"
        ".long 0x807F0000\n"
        ".long 0x2C030000\n"
        ".long 0x4182001C\n"
        ".long 0x4BFFBCCD\n"
        ".long 0x7C03E000\n"
        ".long 0x40820010\n"
        ".long 0x2C1E0000\n"
        ".long 0x40820008\n"
        ".long 0x83DF0000\n"
        ".long 0x801D0004\n"
        ".long 0x3BFF0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x4082FFD0\n"
        ".long 0x7FC3F378\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810008\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
