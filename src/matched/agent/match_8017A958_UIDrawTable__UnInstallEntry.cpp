// 0x8017A958 (84 bytes)
// UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)

class UIDrawTable { public: void UnInstallEntry(CBFunctor1<ERC *> &); };

__attribute__((naked))
void UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C8B2378\n.long 0x80830000\n.long 0x2C040000\n.long 0x41820028\n.long 0x8004000C\n.long 0x81240004\n.long 0x7C005800\n.long 0x40820010\n.long 0x4BFFFEDD\n.long 0x38600001\n.long 0x48000010\n.long 0x7D244B79\n.long 0x4082FFE0\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
