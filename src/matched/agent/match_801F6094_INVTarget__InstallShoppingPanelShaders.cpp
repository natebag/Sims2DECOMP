// 0x801F6094 (64 bytes)
// INVTarget::InstallShoppingPanelShaders(void)

class INVTarget { public: void InstallShoppingPanelShaders(void); };

__attribute__((naked))
void INVTarget::InstallShoppingPanelShaders(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x4800002D\n.long 0x7FC3F378\n.long 0x4800DCB9\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x4800001D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
