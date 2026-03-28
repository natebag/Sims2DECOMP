// 0x8017AA50 (100 bytes)
// UIDrawTable::ExecuteDrawsPreFlash(ERC *)

class UIDrawTable { public: void ExecuteDrawsPreFlash(ERC *); };

__attribute__((naked))
void UIDrawTable::ExecuteDrawsPreFlash(ERC *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x80630000\n.long 0x7C9E2378\n.long 0x2C030000\n.long 0x41820034\n.long 0x80030008\n.long 0x83E30004\n.long 0x2C000032\n.long 0x4081001C\n.long 0x8123000C\n.long 0x7FC4F378\n.long 0x8009000C\n.long 0x7D234B78\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FE3FB79\n.long 0x4082FFD4\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
