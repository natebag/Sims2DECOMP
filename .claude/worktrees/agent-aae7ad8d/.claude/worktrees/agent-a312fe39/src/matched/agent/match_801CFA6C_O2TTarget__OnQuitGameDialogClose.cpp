// 0x801CFA6C (124 bytes)
// O2TTarget::OnQuitGameDialogClose(int)

class O2TTarget { public: void OnQuitGameDialogClose(int); };

__attribute__((naked))
void O2TTarget::OnQuitGameDialogClose(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x2C040001\n.long 0x40820014\n.long 0x3C60803F\n.long 0x386323E8\n.long 0x4BFA827D\n.long 0x48000040\n.long 0x2C040000\n.long 0x40820014\n.long 0x3C60803F\n.long 0x3863F81C\n.long 0x4BFA8265\n.long 0x48000028\n.long 0x3C60803F\n.long 0x38800000\n.long 0x38633E64\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFA828D\n.long 0x38000000\n.long 0x901F0250\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
