// 0x801F58A0 (104 bytes)
// INVTarget::GetMotiveText(int, unsigned wchar_t *)

class INVTarget { public: void GetMotiveText(int, unsigned wchar_t *); };

__attribute__((naked))
void INVTarget::GetMotiveText(int, unsigned wchar_t *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x816DABFC\n.long 0x7C7E1B78\n.long 0x7CBF2B78\n.long 0x2C0B0000\n.long 0x41820030\n.long 0x812B0000\n.long 0xA8690078\n.long 0x8009007C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C641B78\n.long 0x7FE5FB78\n.long 0x7FC3F378\n.long 0x4BFFFE25\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
