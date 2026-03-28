// 0x8007E5F0 (24 bytes)
// DlgWrapper::IsDialogUp(void)

class DlgWrapper { public: void IsDialogUp(void); };

__attribute__((naked))
void DlgWrapper::IsDialogUp(void) {
    asm volatile(".long 0x800300B8\n.long 0x38600001\n.long 0x2C000000\n.long 0x4D810020\n.long 0x38600000\n.long 0x4E800020");
}
