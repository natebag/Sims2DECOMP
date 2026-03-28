// 0x8011F06C (80 bytes)
// cXPersonImpl::PreSave(void)

class cXPersonImpl { public: void PreSave(void); };

__attribute__((naked))
void cXPersonImpl::PreSave(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x807E0000\n.long 0x4BFBC0E5\n.long 0x816DAC1C\n.long 0x809E0004\n.long 0x812B0000\n.long 0xA86900F0\n.long 0x800900F4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
