// 0x80188D3C (64 bytes)
// HUDTarget::CompleteMenu(int)

class HUDTarget { public: void CompleteMenu(int); };

__attribute__((naked))
void HUDTarget::CompleteMenu(int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x48000069\n.long 0x1FDE00B4\n.long 0x3BDE0740\n.long 0x7C7DF214\n.long 0x4BFFB2A5\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
