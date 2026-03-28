// 0x8035301C (116 bytes)
// Effects::Mat4Copy34(EMat4 &, EMat4 &)

class Effects { public: void Mat4Copy34(EMat4 &, EMat4 &); };

__attribute__((naked))
void Effects::Mat4Copy34(EMat4 &, EMat4 &) {
    asm volatile(".long 0xC0030000\n.long 0x39230010\n.long 0x39640010\n.long 0x39030020\n.long 0xD0040000\n.long 0x39440020\n.long 0xC0030004\n.long 0xD0040004\n.long 0xC1A30008\n.long 0xD1A40008\n.long 0xC003000C\n.long 0xD004000C\n.long 0xC1A30010\n.long 0xD1A40010\n.long 0xC0090004\n.long 0xD00B0004\n.long 0xC1A90008\n.long 0xD1AB0008\n.long 0xC009000C\n.long 0xD00B000C\n.long 0xC1A30020\n.long 0xD1A40020\n.long 0xC0080004\n.long 0xD00A0004\n.long 0xC1A80008\n.long 0xD1AA0008\n.long 0xC008000C\n.long 0xD00A000C\n.long 0x4E800020");
}
