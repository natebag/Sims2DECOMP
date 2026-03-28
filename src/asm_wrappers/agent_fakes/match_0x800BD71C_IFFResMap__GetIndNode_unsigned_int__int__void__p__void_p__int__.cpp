/* IFFResMap::GetIndNode(unsigned int, int, void (*)(void *, int)) at 0x800BD71C (144B) */

struct IFFResMap { void GetIndNode(); };

__attribute__((naked))
void IFFResMap::GetIndNode() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7CBF2B78\n"
        ".long 0x7CDD3378\n"
        ".long 0x38A00000\n"
        ".long 0x4BFFF745\n"
        ".long 0x801E0004\n"
        ".long 0x7C030000\n"
        ".long 0x4182004C\n"
        ".long 0x2C1D0000\n"
        ".long 0x41820008\n"
        ".long 0x93A30014\n"
        ".long 0x2C1F0000\n"
        ".long 0x40810038\n"
        ".long 0x81630000\n"
        ".long 0x3D20BA2E\n"
        ".long 0x80030004\n"
        ".long 0x61298BA3\n"
        ".long 0x7C0B0050\n"
        ".long 0x7C0049D6\n"
        ".long 0x7C001E70\n"
        ".long 0x7C1F0000\n"
        ".long 0x41810014\n"
        ".long 0x1C7F0058\n"
        ".long 0x7C6B1A14\n"
        ".long 0x3863FFA8\n"
        ".long 0x48000008\n"
        ".long 0x38600000\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
