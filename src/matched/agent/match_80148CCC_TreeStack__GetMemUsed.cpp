// 0x80148CCC (92 bytes)
// TreeStack::GetMemUsed(void)

class TreeStack { public: void GetMemUsed(void); };

__attribute__((naked))
void TreeStack::GetMemUsed(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x817F0008\n.long 0x801F000C\n.long 0x7C0B0050\n.long 0x7C091671\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800001C\n.long 0x3929FFFF\n.long 0x5529103A\n.long 0x7C6B482E\n.long 0x4BFFFEAD\n.long 0x801F0000\n.long 0x7C601850\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
