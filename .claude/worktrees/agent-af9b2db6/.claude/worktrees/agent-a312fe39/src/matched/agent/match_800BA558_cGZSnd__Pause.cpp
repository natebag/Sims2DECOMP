// 0x800BA558 (128 bytes)
// cGZSnd::Pause(void)

class cGZSnd { public: void Pause(void); };

__attribute__((naked))
void cGZSnd::Pause(void) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0x93E10024\n.long 0x9001002C\n.long 0x7C7F1B78\n.long 0x809F001C\n.long 0x2C040000\n.long 0x41820044\n.long 0x3D20803E\n.long 0x38000000\n.long 0xC0099CFC\n.long 0x38A10008\n.long 0x90010008\n.long 0xD005000C\n.long 0x816D983C\n.long 0x80010008\n.long 0x60000004\n.long 0x90010008\n.long 0x812B0000\n.long 0xA86900B0\n.long 0x800900B4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x38000001\n.long 0x38600001\n.long 0x901F0010\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0x83E10024\n.long 0x38210028\n.long 0x4E800020");
}
