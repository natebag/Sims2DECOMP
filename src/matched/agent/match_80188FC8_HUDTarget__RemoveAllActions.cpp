// 0x80188FC8 (84 bytes)
// HUDTarget::RemoveAllActions(int)

class HUDTarget { public: void RemoveAllActions(int); };

__attribute__((naked))
void HUDTarget::RemoveAllActions(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x1D24031C\n.long 0x7C6B1B78\n.long 0x39400001\n.long 0x7D295A14\n.long 0x8009010C\n.long 0x2C000000\n.long 0x40820008\n.long 0x39400000\n.long 0x2C0A0000\n.long 0x41820014\n.long 0x1C64031C\n.long 0x38630108\n.long 0x7C6B1A14\n.long 0x4BFFC381\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
