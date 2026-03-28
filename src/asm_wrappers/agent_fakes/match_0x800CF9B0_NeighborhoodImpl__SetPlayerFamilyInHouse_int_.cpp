/* NeighborhoodImpl::SetPlayerFamilyInHouse(int) at 0x800CF9B0 (156B) */

struct NeighborhoodImpl { void SetPlayerFamilyInHouse(); };

__attribute__((naked))
void NeighborhoodImpl::SetPlayerFamilyInHouse() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x816DAC1C\n"
        ".long 0x3D208047\n"
        ".long 0x83C95C5C\n"
        ".long 0x7C9D2378\n"
        ".long 0x812B0000\n"
        ".long 0x7FC4F378\n"
        ".long 0xA8690120\n"
        ".long 0x80090124\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C7F1B78\n"
        ".long 0x2C1E0000\n"
        ".long 0x41820044\n"
        ".long 0x2C1F0000\n"
        ".long 0x4182003C\n"
        ".long 0x813F0000\n"
        ".long 0x7FA4EB78\n"
        ".long 0x800900B4\n"
        ".long 0xA86900B0\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C7F1A14\n"
        ".long 0x4E800021\n"
        ".long 0x813F0000\n"
        ".long 0x38800000\n"
        ".long 0xA8690120\n"
        ".long 0x80090124\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
