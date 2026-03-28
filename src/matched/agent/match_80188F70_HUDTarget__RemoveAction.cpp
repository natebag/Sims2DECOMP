// 0x80188F70 (88 bytes)
// HUDTarget::RemoveAction(int, Interaction *)

class HUDTarget { public: void RemoveAction(int, Interaction *); };

__attribute__((naked))
void HUDTarget::RemoveAction(int, Interaction *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x1D24031C\n.long 0x7C6A1B78\n.long 0x39600001\n.long 0x7D295214\n.long 0x8009010C\n.long 0x2C000000\n.long 0x40820008\n.long 0x39600000\n.long 0x2C0B0000\n.long 0x41820018\n.long 0x1C64031C\n.long 0x7CA42B78\n.long 0x38630108\n.long 0x7C6A1A14\n.long 0x4BFFC245\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
