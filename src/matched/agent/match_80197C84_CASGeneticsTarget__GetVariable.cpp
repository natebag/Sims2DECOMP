// 0x80197C84 (120 bytes)
// CASGeneticsTarget::GetVariable(char *)

class CASGeneticsTarget { public: void GetVariable(char *); };

__attribute__((naked))
void CASGeneticsTarget::GetVariable(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x38600020\n.long 0x4BE6E8D5\n.long 0x7C7F1B78\n.long 0x38000000\n.long 0x3C60803F\n.long 0x981F0000\n.long 0x3863C554\n.long 0x7FC4F378\n.long 0x480ABB81\n.long 0x2C030000\n.long 0x40820024\n.long 0x3D20803F\n.long 0x3969C334\n.long 0x8149C334\n.long 0x890B0006\n.long 0xA00B0004\n.long 0x915F0000\n.long 0xB01F0004\n.long 0x991F0006\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
