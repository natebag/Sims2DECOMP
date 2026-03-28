/* Motives::Init(void) at 0x800C27FC (156B) */

struct Motives { void Init(); };

__attribute__((naked))
void Motives::Init() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E1000C\n"
        ".long 0x90010014\n"
        ".long 0x800D82EC\n"
        ".long 0x7C7F1B78\n"
        ".long 0x2C000000\n"
        ".long 0x40820020\n"
        ".long 0x4BFFF7ED\n"
        ".long 0x81230000\n"
        ".long 0xA8090018\n"
        ".long 0x8129001C\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x38000010\n"
        ".long 0x3D20803E\n"
        ".long 0x7C0903A6\n"
        ".long 0xC009A3A0\n"
        ".long 0x397F0040\n"
        ".long 0x393F003C\n"
        ".long 0xD0090000\n"
        ".long 0x3929FFFC\n"
        ".long 0x4200FFF8\n"
        ".long 0x38000010\n"
        ".long 0x3D20803E\n"
        ".long 0x7C0903A6\n"
        ".long 0xC009A3A0\n"
        ".long 0x396B003C\n"
        ".long 0xD00B0000\n"
        ".long 0x396BFFFC\n"
        ".long 0x4200FFF8\n"
        ".long 0x38000000\n"
        ".long 0x901F0080\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E1000C\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
