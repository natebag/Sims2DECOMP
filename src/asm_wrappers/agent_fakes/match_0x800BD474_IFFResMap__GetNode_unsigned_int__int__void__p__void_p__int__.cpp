/* IFFResMap::GetNode(unsigned int, int, void (*)(void *, int)) at 0x800BD474 (160B) */

struct IFFResMap { void GetNode(); };

__attribute__((naked))
void IFFResMap::GetNode() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810008\n"
        ".long 0x9001001C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7CBC2B78\n"
        ".long 0x7CDD3378\n"
        ".long 0x38A00000\n"
        ".long 0x4BFFF9ED\n"
        ".long 0x801E0004\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C1F0000\n"
        ".long 0x40820010\n"
        ".long 0x48000054\n"
        ".long 0x7FC3F378\n"
        ".long 0x48000050\n"
        ".long 0x2C1D0000\n"
        ".long 0x41820008\n"
        ".long 0x93BF0014\n"
        ".long 0x83DF0000\n"
        ".long 0x801F0004\n"
        ".long 0x7C1E0000\n"
        ".long 0x41820030\n"
        ".long 0x801E0004\n"
        ".long 0x7C00E000\n"
        ".long 0x40820014\n"
        ".long 0xA87E0008\n"
        ".long 0x4BFFF825\n"
        ".long 0x2C030000\n"
        ".long 0x4182FFC4\n"
        ".long 0x801F0004\n"
        ".long 0x3BDE0058\n"
        ".long 0x7C1E0000\n"
        ".long 0x4082FFD8\n"
        ".long 0x38600000\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810008\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
