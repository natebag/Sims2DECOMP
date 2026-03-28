// 0x801838B0 (120 bytes)
// ActionMenu::Animate(void)

class ActionMenu { public: void Animate(void); };

__attribute__((naked))
void ActionMenu::Animate(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x881F0009\n.long 0x2C000005\n.long 0x40820024\n.long 0xA17F0006\n.long 0x893F00A2\n.long 0x7D600734\n.long 0x3929FFFF\n.long 0x7C004800\n.long 0x40800020\n.long 0x380B0001\n.long 0x48000014\n.long 0xA13F0006\n.long 0x2C090000\n.long 0x4182000C\n.long 0x3809FFFF\n.long 0xB01F0006\n.long 0x7FE3FB78\n.long 0x48000209\n.long 0x38000004\n.long 0x981F0009\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
