// 0x801BC938 (76 bytes)
// INGTarget::play_error_sound(void)

class INGTarget { public: void play_error_sound(void); };

__attribute__((naked))
void INGTarget::play_error_sound(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800D84D0\n.long 0x2C000000\n.long 0x40820014\n.long 0x38600078\n.long 0x4811485D\n.long 0x4BFBA769\n.long 0x906D84D0\n.long 0x806D84D0\n.long 0x3C803804\n.long 0x6084219F\n.long 0x4BFBAD05\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
