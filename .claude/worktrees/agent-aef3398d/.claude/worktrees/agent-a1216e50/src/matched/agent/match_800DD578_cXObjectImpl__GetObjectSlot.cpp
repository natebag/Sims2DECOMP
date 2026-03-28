// 0x800DD578 (108 bytes)
// cXObjectImpl::GetObjectSlot(int)

class cXObjectImpl { public: void GetObjectSlot(int); };

__attribute__((naked))
void cXObjectImpl::GetObjectSlot(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7C9F2379\n.long 0x41800028\n.long 0x807E0004\n.long 0x81230004\n.long 0xA80902B0\n.long 0x812902B4\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C1F1800\n.long 0x4180000C\n.long 0x38600000\n.long 0x48000014\n.long 0x387F0001\n.long 0x801E0090\n.long 0x54632834\n.long 0x7C601A14\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
