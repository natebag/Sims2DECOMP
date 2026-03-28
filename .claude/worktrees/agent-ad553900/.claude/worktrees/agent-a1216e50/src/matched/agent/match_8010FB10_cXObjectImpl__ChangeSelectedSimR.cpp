// 0x8010FB10 (104 bytes)
// cXObjectImpl::ChangeSelectedSimR(int)

class cXObjectImpl { public: void ChangeSelectedSimR(int); };

__attribute__((naked))
void cXObjectImpl::ChangeSelectedSimR(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3C608047\n.long 0x7FE4FB78\n.long 0x38635DCC\n.long 0x4BF31199\n.long 0x3D208047\n.long 0x38695B84\n.long 0x812300C4\n.long 0x2C090000\n.long 0x41820020\n.long 0x8009002C\n.long 0x2C000000\n.long 0x40820014\n.long 0x57E92036\n.long 0x7D291A14\n.long 0x80690100\n.long 0x4BF08CC5\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
