// 0x80172C28 (80 bytes)
// CasSimState::CasSimState(void)

class CasSimState { public: void CasSimState(void); };

__attribute__((naked))
void CasSimState::CasSimState(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208046\n.long 0x7C7E1B78\n.long 0x39296248\n.long 0x38000000\n.long 0x901E0000\n.long 0x387E0008\n.long 0x913E0004\n.long 0x4BFF46A9\n.long 0x387E012C\n.long 0x4BFF46A1\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
