// 0x801294C8 (116 bytes)
// cXPersonImpl::SetHilite(int)

class cXPersonImpl { public: void SetHilite(int); };

__attribute__((naked))
void cXPersonImpl::SetHilite(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x709E001F\n.long 0x41820020\n.long 0x813F0000\n.long 0x80090084\n.long 0x7009001F\n.long 0x4082002C\n.long 0x38800001\n.long 0x4800030D\n.long 0x48000020\n.long 0x813F0000\n.long 0x80090084\n.long 0x7009001F\n.long 0x41820010\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x480002ED\n.long 0x807F0000\n.long 0x7FC4F378\n.long 0x4BFB20AD\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
