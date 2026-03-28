// 0x801E93BC (84 bytes)
// GetVar_ImageSlotsAvail::Handler(char *)

class GetVar_ImageSlotsAvail { public: void Handler(char *); };

__attribute__((naked))
void GetVar_ImageSlotsAvail::Handler(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812D8FD8\n.long 0x7C832378\n.long 0x80090084\n.long 0x2C000000\n.long 0x41820010\n.long 0x3D208040\n.long 0x38A9879C\n.long 0x4800000C\n.long 0x3D208040\n.long 0x38A98798\n.long 0x3C808040\n.long 0x388487A4\n.long 0x4CC63182\n.long 0x480F548D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
