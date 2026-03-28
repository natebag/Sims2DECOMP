// 0x8030503C (64 bytes)
// EController::GetBtnResultAny(unsigned int, bool, unsigned int)

class EController { public: void GetBtnResultAny(unsigned int, bool, unsigned int); };

__attribute__((naked))
void EController::GetBtnResultAny(unsigned int, bool, unsigned int) {
    asm volatile(".long 0x7C803039\n.long 0x41820034\n.long 0x2C050000\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x81230200\n.long 0x80090078\n.long 0x2C000000\n.long 0x40820014\n.long 0x38000001\n.long 0x38600001\n.long 0x90090078\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
