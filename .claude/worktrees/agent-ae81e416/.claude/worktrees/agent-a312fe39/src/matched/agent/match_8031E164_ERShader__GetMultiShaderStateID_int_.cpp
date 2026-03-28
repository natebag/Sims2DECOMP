// 0x8031E164 (120 bytes)
// ERShader::GetMultiShaderStateID(int)

class ERShader { public: void GetMultiShaderStateID(int); };

__attribute__((naked))
void ERShader::GetMultiShaderStateID(int) {
    asm volatile(".long 0x80030058\n.long 0x70090002\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x88030044\n.long 0x39200000\n.long 0x540A063E\n.long 0x7C080378\n.long 0x7C095000\n.long 0x40800030\n.long 0x81630048\n.long 0x5484063E\n.long 0x880B0000\n.long 0x7C002000\n.long 0x4182001C\n.long 0x39290001\n.long 0x7C095000\n.long 0x40800010\n.long 0x7C0B48AE\n.long 0x7C002000\n.long 0x4082FFEC\n.long 0x7C094000\n.long 0x41820014\n.long 0x8163004C\n.long 0x5529103A\n.long 0x7C69582E\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
