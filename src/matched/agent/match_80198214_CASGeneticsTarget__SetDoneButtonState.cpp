// 0x80198214 (120 bytes)
// CASGeneticsTarget::SetDoneButtonState(void)

class CASGeneticsTarget { public: void SetDoneButtonState(void); };

__attribute__((naked))
void CASGeneticsTarget::SetDoneButtonState(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x3D208047\n.long 0x81295BC0\n.long 0x8169134C\n.long 0x7D605B78\n.long 0x2C0B0000\n.long 0x40800008\n.long 0x380B0003\n.long 0x81291348\n.long 0x5400003A\n.long 0x7C005850\n.long 0x7D290430\n.long 0x71200001\n.long 0x4182002C\n.long 0x3D20803F\n.long 0x3C60803F\n.long 0x3929C31C\n.long 0x3863C5D4\n.long 0x91210008\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00001\n.long 0x38E10008\n.long 0x4BFDFADD\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
