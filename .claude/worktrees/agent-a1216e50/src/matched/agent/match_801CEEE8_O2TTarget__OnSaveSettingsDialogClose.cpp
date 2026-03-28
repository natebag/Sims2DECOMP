// 0x801CEEE8 (120 bytes)
// O2TTarget::OnSaveSettingsDialogClose(int)

class O2TTarget { public: void OnSaveSettingsDialogClose(int); };

__attribute__((naked))
void O2TTarget::OnSaveSettingsDialogClose(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x2C040001\n.long 0x40820028\n.long 0x801F0088\n.long 0x2C000001\n.long 0x4082000C\n.long 0x4800007D\n.long 0x48000014\n.long 0x2C000002\n.long 0x4082000C\n.long 0x7FE3FB78\n.long 0x48000131\n.long 0x3C60803F\n.long 0x38800000\n.long 0x38633E78\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFA8E15\n.long 0x38000000\n.long 0x901F0258\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
