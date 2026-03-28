// 0x801C2F6C (96 bytes)
// M2MTarget::PopButtonFilters(void)

class M2MTarget { public: void PopButtonFilters(void); };

__attribute__((naked))
void M2MTarget::PopButtonFilters(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x809F0170\n.long 0x2C040000\n.long 0x41820014\n.long 0x38600000\n.long 0x4BFB4B09\n.long 0x38000000\n.long 0x901F0170\n.long 0x809F0174\n.long 0x2C040000\n.long 0x41820014\n.long 0x38600001\n.long 0x4BFB4AED\n.long 0x38000000\n.long 0x901F0174\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
