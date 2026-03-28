// 0x80059798 (72 bytes)
// PlumbBobStack::Pop(PlumbBob *)

class PlumbBobStack { public: void Pop(PlumbBob *); };

__attribute__((naked))
void PlumbBobStack::Pop(PlumbBob *) {
    asm volatile(".long 0x81230000\n.long 0x2C090000\n.long 0x4D820020\n.long 0x3809FFFF\n.long 0x39040128\n.long 0x54092036\n.long 0x90030000\n.long 0x39290004\n.long 0x7D634A14\n.long 0x800B000C\n.long 0x9004016C\n.long 0x7D43482E\n.long 0x800B0008\n.long 0x812B0004\n.long 0x91440128\n.long 0x90080008\n.long 0x91280004\n.long 0x4E800020");
}
