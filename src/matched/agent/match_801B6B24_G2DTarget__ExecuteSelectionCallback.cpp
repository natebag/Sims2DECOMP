// 0x801B6B24 (68 bytes)
// G2DTarget::ExecuteSelectionCallback(int)

class G2DTarget { public: void ExecuteSelectionCallback(int); };

__attribute__((naked))
void G2DTarget::ExecuteSelectionCallback(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x812B0110\n.long 0x2C090000\n.long 0x4182001C\n.long 0x38000000\n.long 0x7D234B78\n.long 0x900B0110\n.long 0x8009000C\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
