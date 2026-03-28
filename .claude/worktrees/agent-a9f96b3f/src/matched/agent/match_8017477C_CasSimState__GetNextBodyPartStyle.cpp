// 0x8017477C (68 bytes)
// CasSimState::GetNextBodyPartStyle(int, int, bool)

class CasSimState { public: void GetNextBodyPartStyle(int, int, bool); };

__attribute__((naked))
void CasSimState::GetNextBodyPartStyle(int, int, bool) {
    asm volatile(".long 0x7C832379\n.long 0x4D800020\n.long 0x7C032800\n.long 0x4C800020\n.long 0x2C060000\n.long 0x38000001\n.long 0x40820008\n.long 0x3800FFFF\n.long 0x7C630214\n.long 0x7C032800\n.long 0x4180000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x2C030000\n.long 0x4C800020\n.long 0x3865FFFF\n.long 0x4E800020");
}
