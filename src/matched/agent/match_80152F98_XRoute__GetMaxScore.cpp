// 0x80152F98 (80 bytes)
// XRoute::GetMaxScore(void)

class XRoute { public: void GetMaxScore(void); };

__attribute__((naked))
void XRoute::GetMaxScore(void) {
    asm volatile(".long 0x80030058\n.long 0x2C00FFFF\n.long 0x40820040\n.long 0x81630000\n.long 0x38000000\n.long 0x81230004\n.long 0x90030058\n.long 0x7C0B4800\n.long 0x41820028\n.long 0x7D2A4B78\n.long 0x812B0008\n.long 0x80030058\n.long 0x7C090000\n.long 0x40810008\n.long 0x91230058\n.long 0x396B0010\n.long 0x7C0B5000\n.long 0x4082FFE4\n.long 0x80630058\n.long 0x4E800020");
}
