// 0x801892FC (100 bytes)
// HUDTarget::ManageHUD(short, short, short)

class HUDTarget { public: void ManageHUD(short, short, short); };

__attribute__((naked))
void HUDTarget::ManageHUD(short, short, short) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x2C050001\n.long 0x41820028\n.long 0x41810010\n.long 0x2C050000\n.long 0x41820014\n.long 0x48000030\n.long 0x2C050002\n.long 0x41820018\n.long 0x48000024\n.long 0x4BFFEB11\n.long 0x4800001C\n.long 0x4BFFEB81\n.long 0x48000014\n.long 0x7C862378\n.long 0x38A00000\n.long 0x38800000\n.long 0x4BFFFE79\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
