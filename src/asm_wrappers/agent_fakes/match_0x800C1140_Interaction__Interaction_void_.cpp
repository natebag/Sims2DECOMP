/* Interaction::Interaction(void) at 0x800C1140 (144B) */

struct Interaction { Interaction(); };

__attribute__((naked))
Interaction::Interaction() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x3D20803E\n"
        ".long 0x7C7E1B78\n"
        ".long 0xC0099F3C\n"
        ".long 0x3BA00000\n"
        ".long 0x3D208046\n"
        ".long 0x3800FFFF\n"
        ".long 0x3929F718\n"
        ".long 0x93BE0008\n"
        ".long 0x93BE000C\n"
        ".long 0x387E0034\n"
        ".long 0x93BE0010\n"
        ".long 0x93BE0028\n"
        ".long 0xB3BE002C\n"
        ".long 0x913E0040\n"
        ".long 0x901E0014\n"
        ".long 0xD01E0030\n"
        ".long 0x4BFE0945\n"
        ".long 0x93BE0024\n"
        ".long 0x7FC3F378\n"
        ".long 0x93BE0038\n"
        ".long 0x93BE0004\n"
        ".long 0xB3BE0018\n"
        ".long 0xB3BE001A\n"
        ".long 0xB3BE001C\n"
        ".long 0xB3BE001E\n"
        ".long 0x93BE003C\n"
        ".long 0x93BE0020\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
