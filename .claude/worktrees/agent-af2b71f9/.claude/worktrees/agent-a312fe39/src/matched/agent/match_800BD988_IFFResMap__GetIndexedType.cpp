// 0x800BD988 (68 bytes)
// IFFResMap::GetIndexedType(int)

class IFFResMap { public: void GetIndexedType(int); };

__attribute__((naked))
void IFFResMap::GetIndexedType(int) {
    asm volatile(".long 0x7C842379\n.long 0x40810038\n.long 0x81630000\n.long 0x3D20AAAA\n.long 0x80030004\n.long 0x6129AAAB\n.long 0x7C0B0050\n.long 0x7C0049D6\n.long 0x7C001E70\n.long 0x7C040000\n.long 0x41810014\n.long 0x1D240018\n.long 0x7D2B4A14\n.long 0x8069FFF8\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
