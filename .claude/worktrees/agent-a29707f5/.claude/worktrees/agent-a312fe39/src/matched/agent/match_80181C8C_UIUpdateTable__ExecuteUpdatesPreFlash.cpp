// 0x80181C8C (100 bytes)
// UIUpdateTable::ExecuteUpdatesPreFlash(void)

class UIUpdateTable { public: void ExecuteUpdatesPreFlash(void); };

__attribute__((naked))
void UIUpdateTable::ExecuteUpdatesPreFlash(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x80630000\n.long 0x2C030000\n.long 0x41820038\n.long 0x80030008\n.long 0x83E30004\n.long 0x2C000032\n.long 0x40810020\n.long 0x8123000C\n.long 0x2C090000\n.long 0x41820014\n.long 0x8009000C\n.long 0x7D234B78\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FE3FB79\n.long 0x4082FFD0\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
