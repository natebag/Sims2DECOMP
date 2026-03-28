// 0x80141208 (108 bytes)
// cSimulatorImpl::Pause(void)

class cSimulatorImpl { public: void Pause(void); };

__attribute__((naked))
void cSimulatorImpl::Pause(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x813F0000\n.long 0xA8690060\n.long 0x80090064\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x40820010\n.long 0x386000BD\n.long 0x38800000\n.long 0x4BF73079\n.long 0xA01F0036\n.long 0x3D20803E\n.long 0xC009D664\n.long 0x60000001\n.long 0xD01F00A8\n.long 0xB01F0036\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
