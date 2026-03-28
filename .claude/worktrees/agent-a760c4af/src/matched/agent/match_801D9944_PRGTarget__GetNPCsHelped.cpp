// 0x801D9944 (92 bytes)
// PRGTarget::GetNPCsHelped(void)

class PRGTarget { public: void GetNPCsHelped(void); };

__attribute__((naked))
void PRGTarget::GetNPCsHelped(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x814DAC1C\n.long 0x3D208047\n.long 0x80895C5C\n.long 0x816A0000\n.long 0x800B0124\n.long 0xA86B0120\n.long 0x7C0803A6\n.long 0x7C6A1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x3880000A\n.long 0xA8090150\n.long 0x81290154\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
