// 0x801C77CC (80 bytes)
// MMUTarget::OnCancelKeyPressed(char *, char *)

class MMUTarget { public: void OnCancelKeyPressed(char *, char *); };

__attribute__((naked))
void MMUTarget::OnCancelKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x800B008C\n.long 0x2C000000\n.long 0x40820028\n.long 0x812B0080\n.long 0x3C80803F\n.long 0x388426E4\n.long 0x38A00000\n.long 0xA8690010\n.long 0x80090014\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
