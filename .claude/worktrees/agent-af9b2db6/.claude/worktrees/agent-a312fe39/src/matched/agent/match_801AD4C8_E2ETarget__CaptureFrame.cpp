// 0x801AD4C8 (124 bytes)
// E2ETarget::CaptureFrame(char *, char *)

class E2ETarget { public: void CaptureFrame(char *, char *); };

__attribute__((naked))
void E2ETarget::CaptureFrame(char *, char *) {
    asm volatile(".long 0x9421FEF0\n.long 0x7C0802A6\n.long 0xBFC10108\n.long 0x90010114\n.long 0x7C7F1B78\n.long 0x83DF00D8\n.long 0x2C1E0001\n.long 0x4082004C\n.long 0x807F00BC\n.long 0x4BE8B965\n.long 0x80BF00D8\n.long 0x3C80803F\n.long 0x93DF0284\n.long 0x3884DDA0\n.long 0x38A50001\n.long 0x38610008\n.long 0x4CC63182\n.long 0x4813137D\n.long 0x813F0080\n.long 0x38A10008\n.long 0x808D88A8\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010114\n.long 0x7C0803A6\n.long 0xBBC10108\n.long 0x38210110\n.long 0x4E800020");
}
