// 0x80011D0C (68 bytes)
// AptViewer::GetCurrentAptButtonFilter(int)

class AptViewer { public: void GetCurrentAptButtonFilter(int); };

__attribute__((naked))
void AptViewer::GetCurrentAptButtonFilter(int) {
    asm volatile(".long 0x800303A8\n.long 0x2C000000\n.long 0x4082000C\n.long 0x3860FFFF\n.long 0x4E800020\n.long 0x28040001\n.long 0x40810008\n.long 0x38800000\n.long 0x39230450\n.long 0x1D040050\n.long 0x548B103A\n.long 0x7C09582E\n.long 0x394303B0\n.long 0x54001838\n.long 0x7C004214\n.long 0x7C6A002E\n.long 0x4E800020");
}
