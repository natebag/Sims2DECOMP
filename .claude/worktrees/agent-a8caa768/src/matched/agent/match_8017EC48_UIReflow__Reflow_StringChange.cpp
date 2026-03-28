// 0x8017EC48 (84 bytes)
// UIReflow::Reflow_StringChange(char *)

class UIReflow { public: void Reflow_StringChange(char *); };

__attribute__((naked))
void UIReflow::Reflow_StringChange(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C9D2378\n.long 0x7C7E1B78\n.long 0x3C80803E\n.long 0x388437F8\n.long 0x4BFFF3C1\n.long 0x7FA4EB78\n.long 0x7FC3F378\n.long 0x4BFFF3B5\n.long 0x3C80803E\n.long 0x7FC3F378\n.long 0x38843804\n.long 0x4BFFF3A5\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
