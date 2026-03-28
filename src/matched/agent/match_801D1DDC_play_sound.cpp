// 0x801D1DDC (100 bytes)
// play_sound(unsigned int)

__attribute__((naked))
void play_sound(unsigned int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x800D84D0\n.long 0x7C7F1B78\n.long 0x2C000000\n.long 0x40820014\n.long 0x38600078\n.long 0x480FF3B1\n.long 0x4BFA52BD\n.long 0x906D84D0\n.long 0x806D84D0\n.long 0x2C030000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000010\n.long 0x7FE4FB78\n.long 0x4BFA584D\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
