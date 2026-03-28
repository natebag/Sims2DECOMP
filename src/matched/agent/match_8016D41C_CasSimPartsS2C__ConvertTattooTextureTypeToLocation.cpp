// 0x8016D41C (68 bytes)
// CasSimPartsS2C::ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C) const

class CasSimPartsS2C { public: void ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C) const; };

__attribute__((naked))
void CasSimPartsS2C::ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C) const {
    asm volatile(".long 0x2C040001\n.long 0x41820028\n.long 0x41810010\n.long 0x2C040000\n.long 0x41820014\n.long 0x48000028\n.long 0x2C040002\n.long 0x41820018\n.long 0x4800001C\n.long 0x38600000\n.long 0x4E800020\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600001\n.long 0x4E800020");
}
