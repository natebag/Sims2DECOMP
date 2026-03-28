// 0x8007CFD4 (68 bytes)
// CTGFileImpl::ReadBytes(unsigned char *, int)

class CTGFileImpl { public: void ReadBytes(unsigned char *, int); };

__attribute__((naked))
void CTGFileImpl::ReadBytes(unsigned char *, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0xA8090010\n.long 0x81290014\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600001\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
