// 0x800C6E44 (120 bytes)
// cXMTObjectImpl::SetMultiObjectData(int, int)

class cXMTObjectImpl { public: void SetMultiObjectData(int, int); };

__attribute__((naked))
void cXMTObjectImpl::SetMultiObjectData(int, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x8003000C\n.long 0x7C9D2378\n.long 0x7CBE2B78\n.long 0x7C7F1B78\n.long 0x2C000000\n.long 0x41820038\n.long 0x7C1F0378\n.long 0x48000030\n.long 0x815F0000\n.long 0x7FA4EB78\n.long 0x7FC50734\n.long 0x816A0004\n.long 0x812B0004\n.long 0xA86901E8\n.long 0x800901EC\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x83FF0008\n.long 0x2C1F0000\n.long 0x4082FFD0\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
