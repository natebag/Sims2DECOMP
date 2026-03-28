// 0x800E1540 (84 bytes)
// cXObjectImpl::GetFrontFaceDirection(void)

class cXObjectImpl { public: void GetFrontFaceDirection(void); };

__attribute__((naked))
void cXObjectImpl::GetFrontFaceDirection(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x8083008C\n.long 0x81640050\n.long 0x812B0000\n.long 0xA86900A0\n.long 0x800900A4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C631B79\n.long 0x41820010\n.long 0x81230038\n.long 0xA869007A\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
