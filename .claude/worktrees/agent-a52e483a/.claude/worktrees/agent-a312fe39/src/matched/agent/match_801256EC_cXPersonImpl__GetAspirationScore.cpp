// 0x801256EC (96 bytes)
// cXPersonImpl::GetAspirationScore(void)

class cXPersonImpl { public: void GetAspirationScore(void); };

__attribute__((naked))
void cXPersonImpl::GetAspirationScore(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630004\n.long 0x38800000\n.long 0x812B0004\n.long 0xA8690058\n.long 0x8009005C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x3D20803E\n.long 0x3D60803E\n.long 0xC1A9CD48\n.long 0x3D40803E\n.long 0xC18BCD4C\n.long 0xEC21682A\n.long 0xC00ACD50\n.long 0xEC216024\n.long 0xEC210032\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
