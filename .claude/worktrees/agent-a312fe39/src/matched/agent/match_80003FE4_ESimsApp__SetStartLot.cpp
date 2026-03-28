// 0x80003FE4 (8 bytes)
// ESimsApp::SetStartLot(int)

class ESimsApp { public: void SetStartLot(int); };

__attribute__((naked))
void ESimsApp::SetStartLot(int) {
    asm volatile(".long 0x908D8010\n.long 0x4E800020");
}
