// 0x801E9410 (112 bytes)
// GetVar_EYE_connectionStatus::Handler(char *)

class GetVar_EYE_connectionStatus { public: void Handler(char *); };

__attribute__((naked))
void GetVar_EYE_connectionStatus::Handler(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x4BE4FBBD\n.long 0x812D8FD8\n.long 0x2C030000\n.long 0x906900B0\n.long 0x41820010\n.long 0x3D208040\n.long 0x38A98798\n.long 0x4800000C\n.long 0x3D208040\n.long 0x38A9879C\n.long 0x3C808040\n.long 0x7FE3FB78\n.long 0x388487A4\n.long 0x4CC63182\n.long 0x480F542D\n.long 0x812D8FD8\n.long 0x38000000\n.long 0x900900B0\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
