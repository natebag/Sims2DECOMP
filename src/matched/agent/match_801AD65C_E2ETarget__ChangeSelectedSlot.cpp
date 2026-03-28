// 0x801AD65C (100 bytes)
// E2ETarget::ChangeSelectedSlot(char *, char *)

class E2ETarget { public: void ChangeSelectedSlot(char *, char *); };

__attribute__((naked))
void E2ETarget::ChangeSelectedSlot(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CA32B78\n.long 0x481315DD\n.long 0x7C631B79\n.long 0x40800014\n.long 0x813F00B4\n.long 0x3929FFFF\n.long 0x913F00C0\n.long 0x48000020\n.long 0x801F00B4\n.long 0x7C030000\n.long 0x41800010\n.long 0x38000000\n.long 0x901F00C0\n.long 0x48000008\n.long 0x907F00C0\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
