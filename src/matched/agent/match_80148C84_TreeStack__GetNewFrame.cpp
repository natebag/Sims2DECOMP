// 0x80148C84 (72 bytes)
// TreeStack::GetNewFrame(void)

class TreeStack { public: void GetNewFrame(void); };

__attribute__((naked))
void TreeStack::GetNewFrame(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630008\n.long 0x8003000C\n.long 0x7C0B0050\n.long 0x7C091671\n.long 0x4082000C\n.long 0x80630000\n.long 0x48000014\n.long 0x3929FFFF\n.long 0x5529103A\n.long 0x7C6B482E\n.long 0x4BFFFEFD\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
