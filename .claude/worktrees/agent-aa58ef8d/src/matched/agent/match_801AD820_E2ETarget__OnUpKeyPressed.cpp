// 0x801AD820 (64 bytes)
// E2ETarget::OnUpKeyPressed(char *, char *)

class E2ETarget { public: void OnUpKeyPressed(char *, char *); };

__attribute__((naked))
void E2ETarget::OnUpKeyPressed(char *, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x812B00A8\n.long 0x814B00AC\n.long 0x39290001\n.long 0x7C095396\n.long 0x7C0051D6\n.long 0x7D204850\n.long 0x912B00A8\n.long 0x48000405\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
