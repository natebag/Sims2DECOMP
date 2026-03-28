// 0x80196420 (84 bytes)
// CASTarget::ResetSimRotations(void)

class CASTarget { public: void ResetSimRotations(void); };

__attribute__((naked))
void CASTarget::ResetSimRotations(void) {
    asm volatile(".long 0x38000004\n.long 0x3D20803F\n.long 0x7C0903A6\n.long 0xC009C460\n.long 0x39600000\n.long 0x39430A48\n.long 0x7D605B78\n.long 0x2C0B0000\n.long 0x40800008\n.long 0x380B0003\n.long 0x5400003A\n.long 0x81231348\n.long 0x7C005850\n.long 0x7D290430\n.long 0x71200001\n.long 0x41820008\n.long 0xD00A020C\n.long 0x394A0240\n.long 0x396B0001\n.long 0x4200FFCC\n.long 0x4E800020");
}
