/* Neighbor::GetRelationshipById(int, int *) at 0x800CA388 (156B) */

struct Neighbor { void GetRelationshipById(); };

__attribute__((naked))
void Neighbor::GetRelationshipById() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7E1B78\n"
        ".long 0x7C9D2378\n"
        ".long 0x807E0010\n"
        ".long 0x7CBF2B78\n"
        ".long 0x81230000\n"
        ".long 0xA8090020\n"
        ".long 0x81290024\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C631B79\n"
        ".long 0x40820018\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820008\n"
        ".long 0x907F0000\n"
        ".long 0x38600000\n"
        ".long 0x48000038\n"
        ".long 0x2C1F0000\n"
        ".long 0x4182002C\n"
        ".long 0x807E0010\n"
        ".long 0x7FA4EB78\n"
        ".long 0x38A00000\n"
        ".long 0x81230000\n"
        ".long 0xA8090040\n"
        ".long 0x81290044\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x907F0000\n"
        ".long 0x38600001\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
