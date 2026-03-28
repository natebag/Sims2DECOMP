// 0x8012B4AC (124 bytes)
// cXPersonImpl::IsMale(void)

class cXPersonImpl { public: void IsMale(void); };

__attribute__((naked))
void cXPersonImpl::IsMale(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0004\n.long 0x81230004\n.long 0xA8090150\n.long 0x81290154\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C631B79\n.long 0x40820030\n.long 0x817F0004\n.long 0x812B0004\n.long 0x80090164\n.long 0xA8690160\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x80630000\n.long 0x20030000\n.long 0x7C601914\n.long 0x48000008\n.long 0x80630084\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
