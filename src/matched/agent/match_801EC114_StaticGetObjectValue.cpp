// 0x801EC114 (68 bytes)
// StaticGetObjectValue(ObjSelector *)

__attribute__((naked))
void StaticGetObjectValue(ObjSelector *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C601B79\n.long 0x38600000\n.long 0x41820020\n.long 0x7C030378\n.long 0x4BF24711\n.long 0x81230038\n.long 0x2C090000\n.long 0x38600000\n.long 0x41820008\n.long 0xA8690024\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
