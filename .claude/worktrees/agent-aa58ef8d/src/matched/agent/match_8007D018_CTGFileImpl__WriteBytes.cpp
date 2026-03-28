// 0x8007D018 (76 bytes)
// CTGFileImpl::WriteBytes(unsigned char *, int)

class CTGFileImpl { public: void WriteBytes(unsigned char *, int); };

__attribute__((naked))
void CTGFileImpl::WriteBytes(unsigned char *, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x81230000\n.long 0x7CBE2B78\n.long 0xA8090018\n.long 0x8129001C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C63F278\n.long 0x20030000\n.long 0x7C601914\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
