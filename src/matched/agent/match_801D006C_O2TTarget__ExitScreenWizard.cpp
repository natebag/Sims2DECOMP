// 0x801D006C (84 bytes)
// O2TTarget::ExitScreenWizard(char *, char *)

class O2TTarget { public: void ExitScreenWizard(char *, char *); };

__attribute__((naked))
void O2TTarget::ExitScreenWizard(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030000\n.long 0x3D20803F\n.long 0x38893988\n.long 0x2C000000\n.long 0x41820028\n.long 0x8003001C\n.long 0x2C000000\n.long 0x4182001C\n.long 0x80C3007C\n.long 0x3CA09F93\n.long 0x7C030378\n.long 0x60A5FF74\n.long 0x38E00000\n.long 0x4BFA630D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
