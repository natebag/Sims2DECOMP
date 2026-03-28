// 0x800EAC00 (100 bytes)
// cXObjectImpl::RequiresWallAdjacency(void)

class cXObjectImpl { public: void RequiresWallAdjacency(void); };

__attribute__((naked))
void cXObjectImpl::RequiresWallAdjacency(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630004\n.long 0x812B0004\n.long 0x800901CC\n.long 0xA86901C8\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x38800006\n.long 0xA8090070\n.long 0x81290074\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600001\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
