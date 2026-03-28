// 0x801C3DA0 (80 bytes)
// MDITarget::AddToList(MDITarget::ModelessDialog *)

class MDITarget { public: void AddToList(MDITarget::ModelessDialog *); };

__attribute__((naked))
void MDITarget::AddToList(MDITarget::ModelessDialog *) {
    asm volatile(".long 0x81630084\n.long 0x38000001\n.long 0x90030088\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x90830084\n.long 0x4E800020\n.long 0x39200002\n.long 0x48000010\n.long 0x81230088\n.long 0x816B0020\n.long 0x39290001\n.long 0x91230088\n.long 0x800B0020\n.long 0x2C000000\n.long 0x4082FFE8\n.long 0x908B0020\n.long 0x38000000\n.long 0x90040020\n.long 0x4E800020");
}
