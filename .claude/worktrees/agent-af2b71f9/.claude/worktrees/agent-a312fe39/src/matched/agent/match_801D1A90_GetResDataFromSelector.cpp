// 0x801D1A90 (64 bytes)
// GetResDataFromSelector(ObjSelector *)

__attribute__((naked))
void GetResDataFromSelector(ObjSelector *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x4BFFFF75\n.long 0x7C631B79\n.long 0x41820018\n.long 0x80630038\n.long 0x2C030000\n.long 0x4182000C\n.long 0x806300C0\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
