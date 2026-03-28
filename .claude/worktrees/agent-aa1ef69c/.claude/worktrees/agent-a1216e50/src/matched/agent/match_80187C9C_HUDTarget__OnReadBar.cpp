// 0x80187C9C (116 bytes)
// HUDTarget::OnReadBar(int, unsigned int)

class HUDTarget { public: void OnReadBar(int, unsigned int); };

__attribute__((naked))
void HUDTarget::OnReadBar(int, unsigned int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0xA01F00C8\n.long 0x2C000009\n.long 0x41810034\n.long 0x2C000001\n.long 0x4180002C\n.long 0x2C050005\n.long 0x40820030\n.long 0x801F00A0\n.long 0x2C000000\n.long 0x41820024\n.long 0x480018D1\n.long 0x1C1E0006\n.long 0x393F00A9\n.long 0x7C6901AE\n.long 0x48000010\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x48000019\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
