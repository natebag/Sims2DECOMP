// 0x800EAABC (124 bytes)
// cXObjectImpl::IsEmissive(void)

class cXObjectImpl { public: void IsEmissive(void); };

__attribute__((naked))
void cXObjectImpl::IsEmissive(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3BC00000\n.long 0x807F0004\n.long 0x81230004\n.long 0xA8090418\n.long 0x8129041C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x4182002C\n.long 0x807F0004\n.long 0x81230004\n.long 0xA8090318\n.long 0x8129031C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030008\n.long 0x41820008\n.long 0x3BC00001\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
