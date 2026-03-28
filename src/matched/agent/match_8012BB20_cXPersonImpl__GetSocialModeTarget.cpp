// 0x8012BB20 (108 bytes)
// cXPersonImpl::GetSocialModeTarget(void)

class cXPersonImpl { public: void GetSocialModeTarget(void); };

__attribute__((naked))
void cXPersonImpl::GetSocialModeTarget(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0xA8830058\n.long 0x2C040000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000040\n.long 0x81630000\n.long 0x814B0004\n.long 0x812A0004\n.long 0xA8690488\n.long 0x8009048C\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C631B79\n.long 0x41820014\n.long 0x80630000\n.long 0x38800002\n.long 0x4BFC7035\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
