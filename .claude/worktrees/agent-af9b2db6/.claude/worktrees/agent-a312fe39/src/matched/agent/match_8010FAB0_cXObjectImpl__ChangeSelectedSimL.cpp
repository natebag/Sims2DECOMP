// 0x8010FAB0 (96 bytes)
// cXObjectImpl::ChangeSelectedSimL(int)

class cXObjectImpl { public: void ChangeSelectedSimL(int); };

__attribute__((naked))
void cXObjectImpl::ChangeSelectedSimL(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x3C608047\n.long 0x7FC4F378\n.long 0x38635DCC\n.long 0x4BF31599\n.long 0x3D208047\n.long 0x57DE2036\n.long 0x39295B84\n.long 0x7D7E4A14\n.long 0x800B0100\n.long 0x2C000000\n.long 0x41820010\n.long 0x7D695B78\n.long 0x80690100\n.long 0x4BF08D2D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
