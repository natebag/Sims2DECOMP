// 0x801E6DF0 (64 bytes)
// WXFTarget::onHelpDialogSelection(int)

class WXFTarget { public: void onHelpDialogSelection(int); };

__attribute__((naked))
void WXFTarget::onHelpDialogSelection(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230130\n.long 0x39290001\n.long 0x28090002\n.long 0x91230130\n.long 0x4181000C\n.long 0x48000021\n.long 0x4800000C\n.long 0x38000000\n.long 0x90030130\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
