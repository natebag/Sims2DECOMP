// 0x800AABC4 (64 bytes)
// AnimTableImpl::GetEntry(int)

class AnimTableImpl { public: void GetEntry(int); };

__attribute__((naked))
void AnimTableImpl::GetEntry(int) {
    asm volatile(".long 0x81230004\n.long 0x38000000\n.long 0x80690000\n.long 0x2C030000\n.long 0x41820008\n.long 0x8003FFFC\n.long 0x7C040000\n.long 0x4080001C\n.long 0x5489103A\n.long 0x7C63482E\n.long 0x2C030000\n.long 0x4182000C\n.long 0x80630000\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
