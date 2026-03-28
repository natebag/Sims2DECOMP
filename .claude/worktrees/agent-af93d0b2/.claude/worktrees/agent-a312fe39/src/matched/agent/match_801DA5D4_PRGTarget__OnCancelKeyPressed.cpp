// 0x801DA5D4 (76 bytes)
// PRGTarget::OnCancelKeyPressed(char *, char *)

class PRGTarget { public: void OnCancelKeyPressed(char *, char *); };

__attribute__((naked))
void PRGTarget::OnCancelKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D208047\n.long 0x3C80803F\n.long 0x81695EF8\n.long 0x3CA0803F\n.long 0x3884EB18\n.long 0x38A5EB24\n.long 0x812B0080\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
