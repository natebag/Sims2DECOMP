// 0x8012640C (92 bytes)
// cXPersonImpl::GetCurrentInteractionStackObject(void)

class cXPersonImpl { public: void GetCurrentInteractionStackObject(void); };

__attribute__((naked))
void cXPersonImpl::GetCurrentInteractionStackObject(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030534\n.long 0x2C000000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000030\n.long 0x38630130\n.long 0x3C00CCCC\n.long 0x812302A8\n.long 0x6000CCCD\n.long 0x7C090016\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7D204850\n.long 0x1D290044\n.long 0x7C634A14\n.long 0x4BF9B821\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
