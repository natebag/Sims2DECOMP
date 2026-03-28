// 0x801AD860 (64 bytes)
// E2ETarget::OnDownKeyPressed(char *, char *)

class E2ETarget { public: void OnDownKeyPressed(char *, char *); };

__attribute__((naked))
void E2ETarget::OnDownKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812300A8\n.long 0x3929FFFF\n.long 0x2C090000\n.long 0x912300A8\n.long 0x40800010\n.long 0x812300AC\n.long 0x3929FFFF\n.long 0x912300A8\n.long 0x480003C5\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
