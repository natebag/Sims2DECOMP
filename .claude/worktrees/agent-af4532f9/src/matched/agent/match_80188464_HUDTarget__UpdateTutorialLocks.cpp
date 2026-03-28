// 0x80188464 (80 bytes)
// HUDTarget::UpdateTutorialLocks(void)

class HUDTarget { public: void UpdateTutorialLocks(void); };

__attribute__((naked))
void HUDTarget::UpdateTutorialLocks(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x812D8520\n.long 0x39600001\n.long 0x800300EC\n.long 0x7C090000\n.long 0x40820008\n.long 0x39600000\n.long 0x2C0B0000\n.long 0x912300EC\n.long 0x912300F0\n.long 0x41820010\n.long 0x2C090001\n.long 0x40820008\n.long 0x4BFFF99D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
