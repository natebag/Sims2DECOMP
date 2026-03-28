/* IFFResNode::DoStream(ReconBuffer *, int) at 0x800BCD20 (140B) */

struct IFFResNode { void DoStream(); };

__attribute__((naked))
void IFFResNode::DoStream() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10010\n"
        ".long 0x9001001C\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9E2378\n"
        ".long 0x7FC3F378\n"
        ".long 0x7FE4FB78\n"
        ".long 0x38A00001\n"
        ".long 0x480768F1\n"
        ".long 0xA81F0006\n"
        ".long 0x38810008\n"
        ".long 0x7FC3F378\n"
        ".long 0x38A00001\n"
        ".long 0xB0010008\n"
        ".long 0x48076729\n"
        ".long 0xA8010008\n"
        ".long 0x7FC3F378\n"
        ".long 0x389F000A\n"
        ".long 0x38A00001\n"
        ".long 0x901F0004\n"
        ".long 0x48076711\n"
        ".long 0x801E000C\n"
        ".long 0x2C000000\n"
        ".long 0x4082000C\n"
        ".long 0xA01F000A\n"
        ".long 0xB01F0008\n"
        ".long 0x7FC3F378\n"
        ".long 0x389F0010\n"
        ".long 0x4807713D\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10010\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
