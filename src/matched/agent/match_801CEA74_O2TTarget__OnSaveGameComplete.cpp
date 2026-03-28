// 0x801CEA74 (76 bytes)
// O2TTarget::OnSaveGameComplete(bool)

class O2TTarget { public: void OnSaveGameComplete(bool); };

__attribute__((naked))
void O2TTarget::OnSaveGameComplete(bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800000\n.long 0x3C60803F\n.long 0x38A00000\n.long 0x38633E64\n.long 0x38C00000\n.long 0x38E00000\n.long 0x4BFA92B5\n.long 0x38000000\n.long 0x901E0090\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
