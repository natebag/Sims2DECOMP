// 0x801E9350 (108 bytes)
// GetVar_SaveRequired::Handler(char *)

class GetVar_SaveRequired { public: void Handler(char *); };

__attribute__((naked))
void GetVar_SaveRequired::Handler(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812D8FD8\n.long 0x7C832378\n.long 0x39600000\n.long 0x80090088\n.long 0x2C000000\n.long 0x40810010\n.long 0x800900B0\n.long 0x21200000\n.long 0x7D690114\n.long 0x2C0B0000\n.long 0x41820010\n.long 0x3D208040\n.long 0x38A9879C\n.long 0x4800000C\n.long 0x3D208040\n.long 0x38A98798\n.long 0x3C808040\n.long 0x388487A4\n.long 0x4CC63182\n.long 0x480F54E1\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
