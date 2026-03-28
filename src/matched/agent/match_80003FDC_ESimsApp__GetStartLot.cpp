// 0x80003FDC (8 bytes)
// ESimsApp::GetStartLot(void)

class ESimsApp { public: void GetStartLot(void); };

__attribute__((naked))
void ESimsApp::GetStartLot(void) {
    asm volatile(".long 0x806D8010\n.long 0x4E800020");
}
