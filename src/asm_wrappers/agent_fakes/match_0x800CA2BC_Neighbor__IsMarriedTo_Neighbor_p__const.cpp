/* Neighbor::IsMarriedTo(Neighbor *) const at 0x800CA2BC (140B) */

struct Neighbor { void IsMarriedTo(); };

__attribute__((naked))
void Neighbor::IsMarriedTo() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9E2379\n"
        ".long 0x4182005C\n"
        ".long 0x807F0010\n"
        ".long 0xA89E0004\n"
        ".long 0x81230000\n"
        ".long 0xA8090020\n"
        ".long 0x81290024\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x2C030003\n"
        ".long 0x40810034\n"
        ".long 0x807F0010\n"
        ".long 0x38A00003\n"
        ".long 0xA89E0004\n"
        ".long 0x81230000\n"
        ".long 0xA8090040\n"
        ".long 0x81290044\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x70600010\n"
        ".long 0x38600001\n"
        ".long 0x40820008\n"
        ".long 0x38600000\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
