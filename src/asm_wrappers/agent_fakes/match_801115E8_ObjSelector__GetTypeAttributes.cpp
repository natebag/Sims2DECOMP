// 0x801115E8 (96 bytes)
// ObjSelector::GetTypeAttributes(void)

class ObjSelector { public: void GetTypeAttributes(void); };

__attribute__((naked))
void ObjSelector::GetTypeAttributes(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230038\n.long 0x808900B8\n.long 0x2C040000\n.long 0x40820008\n.long 0x8089001C\n.long 0x80630050\n.long 0x81230000\n.long 0xA80900B0\n.long 0x812900B4\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C631B79\n.long 0x4182000C\n.long 0x80630008\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
