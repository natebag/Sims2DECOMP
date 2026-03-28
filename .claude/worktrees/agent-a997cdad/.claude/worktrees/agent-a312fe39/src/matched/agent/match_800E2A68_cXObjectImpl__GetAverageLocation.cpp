// 0x800E2A68 (92 bytes)
// cXObjectImpl::GetAverageLocation(void) const

class cXObjectImpl { public: void GetAverageLocation(void) const; };

__attribute__((naked))
void cXObjectImpl::GetAverageLocation(void) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFC10010\n.long 0x9001001C\n.long 0x81640004\n.long 0x7C7E1B78\n.long 0x38810008\n.long 0x812B0004\n.long 0xA8690338\n.long 0x8009033C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x81210008\n.long 0x8141000C\n.long 0x7FC3F378\n.long 0x913E0000\n.long 0x915E0004\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10010\n.long 0x38210018\n.long 0x4E800020");
}
