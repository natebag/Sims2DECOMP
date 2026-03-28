// 0x8032086C (72 bytes)
// ERShader::IsMultiTextureShader(void)

class ERShader { public: void IsMultiTextureShader(void); };

__attribute__((naked))
void ERShader::IsMultiTextureShader(void) {
    asm volatile(".long 0x80030058\n.long 0x70090002\n.long 0x4182000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x80030014\n.long 0x2C000000\n.long 0x4182000C\n.long 0x7C090378\n.long 0x48000018\n.long 0x80630018\n.long 0x39200000\n.long 0x2C030000\n.long 0x41820008\n.long 0x81230014\n.long 0x80690004\n.long 0x546337FE\n.long 0x4E800020");
}
