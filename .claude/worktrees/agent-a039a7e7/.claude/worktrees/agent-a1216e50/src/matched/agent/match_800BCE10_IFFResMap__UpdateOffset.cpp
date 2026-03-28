// 0x800BCE10 (112 bytes)
// IFFResMap::UpdateOffset(int, int)

class IFFResMap { public: void UpdateOffset(int, int); };

__attribute__((naked))
void IFFResMap::UpdateOffset(int, int) {
    asm volatile(".long 0x7CA52B79\n.long 0x4080001C\n.long 0x38600000\n.long 0x4E800020\n.long 0x7C050050\n.long 0x38600001\n.long 0x90090000\n.long 0x4E800020\n.long 0x81230004\n.long 0x80630000\n.long 0x7C034800\n.long 0x4182003C\n.long 0x7D2A4B78\n.long 0x81230000\n.long 0x81630004\n.long 0x7C095800\n.long 0x4182001C\n.long 0x80090000\n.long 0x7C002000\n.long 0x4182FFC4\n.long 0x39290058\n.long 0x7C095800\n.long 0x4082FFEC\n.long 0x38630018\n.long 0x7C035000\n.long 0x4082FFD0\n.long 0x38600000\n.long 0x4E800020");
}
