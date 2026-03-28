/* NeighborhoodImpl::GetFamilyIndex(Family *) at 0x800CEB44 (152B) */

struct NeighborhoodImpl { void GetFamilyIndex(); };

__attribute__((naked))
void NeighborhoodImpl::GetFamilyIndex() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810008\n"
        ".long 0x9001001C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7C9C2378\n"
        ".long 0x397E005C\n"
        ".long 0x813E005C\n"
        ".long 0x800B0004\n"
        ".long 0x3BE00000\n"
        ".long 0x7C090050\n"
        ".long 0x5409F0BF\n"
        ".long 0x41820050\n"
        ".long 0x7D7D5B78\n"
        ".long 0x813E0000\n"
        ".long 0x7FE4FB78\n"
        ".long 0xA8690118\n"
        ".long 0x8009011C\n"
        ".long 0x7C7E1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C03E000\n"
        ".long 0x4082000C\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48000024\n"
        ".long 0x813D0004\n"
        ".long 0x3BFF0001\n"
        ".long 0x801E005C\n"
        ".long 0x7D204850\n"
        ".long 0x7D291670\n"
        ".long 0x7C1F4840\n"
        ".long 0x4180FFBC\n"
        ".long 0x3860FFFF\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810008\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
