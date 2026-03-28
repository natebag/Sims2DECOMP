// 0x8011089C (64 bytes)
// ObjSelector::GetOriginal(void)

class ObjSelector { public: void GetOriginal(void); };

__attribute__((naked))
void ObjSelector::GetOriginal(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81430050\n.long 0x81230038\n.long 0x816A0000\n.long 0x8089008C\n.long 0xA86B0078\n.long 0x800B007C\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
