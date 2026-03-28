// 0x8012CA5C (76 bytes)
// cXPersonImpl::GetControllingObject(void)

class cXPersonImpl { public: void GetControllingObject(void); };

__attribute__((naked))
void cXPersonImpl::GetControllingObject(void) {
    asm volatile(".long 0x81630420\n.long 0x3D20AAAA\n.long 0x80030424\n.long 0x6129AAAB\n.long 0x7C0B0050\n.long 0x7C0049D6\n.long 0x7C091671\n.long 0x40810024\n.long 0x3929FFFF\n.long 0x38600000\n.long 0x1D29000C\n.long 0x7D2B482E\n.long 0x2C090000\n.long 0x4D820020\n.long 0x80690004\n.long 0x4E800020\n.long 0x81230004\n.long 0x80690000\n.long 0x4E800020");
}
