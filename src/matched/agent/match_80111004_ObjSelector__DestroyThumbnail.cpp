// 0x80111004 (80 bytes)
// ObjSelector::DestroyThumbnail(void)

class ObjSelector { public: void DestroyThumbnail(void); };

__attribute__((naked))
void ObjSelector::DestroyThumbnail(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0094\n.long 0x2C030000\n.long 0x41820020\n.long 0xA123000C\n.long 0xA803000C\n.long 0x2C000000\n.long 0x41820010\n.long 0x48200F3D\n.long 0x38000000\n.long 0x901F0094\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
