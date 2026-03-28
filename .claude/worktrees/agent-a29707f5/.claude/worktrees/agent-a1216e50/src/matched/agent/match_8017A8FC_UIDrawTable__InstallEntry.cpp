// 0x8017A8FC (92 bytes)
// UIDrawTable::InstallEntry(UIDrawTable::DrawTablePriority, CBFunctor1<ERC *> &, char *)

class UIDrawTable { public: void InstallEntry(UIDrawTable::DrawTablePriority, CBFunctor1<ERC *> &, char *); };

__attribute__((naked))
void UIDrawTable::InstallEntry(UIDrawTable::DrawTablePriority, CBFunctor1<ERC *> &, char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030008\n.long 0x2C000000\n.long 0x41820034\n.long 0x81230000\n.long 0x2C090000\n.long 0x4182001C\n.long 0x8009000C\n.long 0x7C002800\n.long 0x4182001C\n.long 0x81290004\n.long 0x2C090000\n.long 0x4082FFEC\n.long 0x4BFFFE5D\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
