// 0x800418E0 (72 bytes)
// GetObjectInstance(cXObject *)

__attribute__((naked))
void GetObjectInstance(cXObject *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000020\n.long 0x80630000\n.long 0x81230018\n.long 0xA8090098\n.long 0x8129009C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
