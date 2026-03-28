// 0x801F05C8 (88 bytes)
// INVTarget::UpdateInputState(void)

class INVTarget { public: void UpdateInputState(void); };

__attribute__((naked))
void INVTarget::UpdateInputState(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x83CD9864\n.long 0x7C7F1B78\n.long 0x809F0084\n.long 0x7FC3F378\n.long 0x48133029\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x48132FFD\n.long 0x7C631B79\n.long 0x41820010\n.long 0x809F00D0\n.long 0x481151E5\n.long 0x907F008C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
