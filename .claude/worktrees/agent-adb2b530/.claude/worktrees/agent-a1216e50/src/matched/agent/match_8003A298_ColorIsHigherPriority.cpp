// 0x8003A298 (72 bytes)
// ColorIsHigherPriority(Interaction::tColor, Interaction::tColor)

class ColorIsHigherPriority(Interaction { public: void tColor, Interaction::tColor)(); };

__attribute__((naked))
void ColorIsHigherPriority(Interaction::tColor, Interaction::tColor)() {
    asm volatile(".long 0x7F832000\n.long 0x409E000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x2C030004\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x2C040004\n.long 0x4182FFE4\n.long 0x2C030000\n.long 0x4182FFEC\n.long 0x2C040000\n.long 0x38600000\n.long 0x4D820020\n.long 0x7C600026\n.long 0x5463F7FE\n.long 0x4E800020");
}
