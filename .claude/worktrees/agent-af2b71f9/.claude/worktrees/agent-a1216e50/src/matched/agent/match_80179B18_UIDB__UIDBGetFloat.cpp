// 0x80179B18 (72 bytes)
// UIDB::UIDBGetFloat(char *)

class UIDB { public: void UIDBGetFloat(char *); };

__attribute__((naked))
void UIDB::UIDBGetFloat(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800D84E0\n.long 0x2C000000\n.long 0x41820014\n.long 0x38800066\n.long 0x480001D1\n.long 0x7C631B79\n.long 0x40820010\n.long 0x3D20803E\n.long 0xC0292C24\n.long 0x48000008\n.long 0xC0230008\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
