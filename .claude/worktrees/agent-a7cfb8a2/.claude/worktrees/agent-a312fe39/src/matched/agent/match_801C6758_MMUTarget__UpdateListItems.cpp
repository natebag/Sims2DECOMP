// 0x801C6758 (68 bytes)
// MMUTarget::UpdateListItems(void)

class MMUTarget { public: void UpdateListItems(void); };

__attribute__((naked))
void MMUTarget::UpdateListItems(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x8003008C\n.long 0x2C000000\n.long 0x4182000C\n.long 0x2C000001\n.long 0x4082000C\n.long 0x48000025\n.long 0x48000010\n.long 0x2C000002\n.long 0x40820008\n.long 0x48000161\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
