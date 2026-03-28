// 0x801F0868 (84 bytes)
// INVTarget::PopCurrentFilter(void)

class INVTarget { public: void PopCurrentFilter(void); };

__attribute__((naked))
void INVTarget::PopCurrentFilter(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x83AD9864\n.long 0x809E0084\n.long 0x7FA3EB78\n.long 0x48132D89\n.long 0x7C641B78\n.long 0x7FA3EB78\n.long 0x48132D5D\n.long 0x809E00D0\n.long 0x48114A51\n.long 0x38000000\n.long 0x901E00D0\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
