// 0x80195C40 (64 bytes)
// CASTarget::ShowAllCFAOptions(void)

class CASTarget { public: void ShowAllCFAOptions(void); };

__attribute__((naked))
void CASTarget::ShowAllCFAOptions(void) {
    asm volatile(".long 0x80030104\n.long 0x2C000004\n.long 0x41810020\n.long 0x2C000002\n.long 0x40800028\n.long 0x2C000000\n.long 0x41820020\n.long 0x2C000001\n.long 0x41820010\n.long 0x48000014\n.long 0x2C000005\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
