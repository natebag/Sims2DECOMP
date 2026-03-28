// 0x8007D114 (64 bytes)
// CTGFileImpl::WriteInteger(int)

class CTGFileImpl { public: void WriteInteger(int); };

__attribute__((naked))
void CTGFileImpl::WriteInteger(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x90810008\n.long 0x38A00004\n.long 0x38810008\n.long 0x81230000\n.long 0xA8090050\n.long 0x81290054\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
