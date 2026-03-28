// 0x800EB230 (112 bytes)
// cXObjectImpl::GetContainedObject(int)

class cXObjectImpl { public: void GetContainedObject(int); };

__attribute__((naked))
void cXObjectImpl::GetContainedObject(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x807F0004\n.long 0x81230004\n.long 0xA80902B8\n.long 0x812902BC\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C691B79\n.long 0x38600000\n.long 0x41820024\n.long 0x807F0004\n.long 0xA8890004\n.long 0x81230004\n.long 0xA8090488\n.long 0x8129048C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
