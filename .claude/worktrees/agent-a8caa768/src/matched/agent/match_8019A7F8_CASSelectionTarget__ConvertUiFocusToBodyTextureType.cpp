// 0x8019A7F8 (92 bytes)
// CASSelectionTarget::ConvertUiFocusToBodyTextureType(unsigned int, eTattooTextureTypeS2C *)

class CASSelectionTarget { public: void ConvertUiFocusToBodyTextureType(unsigned int, eTattooTextureTypeS2C *); };

__attribute__((naked))
void CASSelectionTarget::ConvertUiFocusToBodyTextureType(unsigned int, eTattooTextureTypeS2C *) {
    asm volatile(".long 0x2C040040\n.long 0x41820030\n.long 0x28040040\n.long 0x41810010\n.long 0x2C04003F\n.long 0x41820014\n.long 0x48000034\n.long 0x2C040041\n.long 0x41820020\n.long 0x48000028\n.long 0x38000000\n.long 0x90050000\n.long 0x48000024\n.long 0x38000001\n.long 0x90050000\n.long 0x48000018\n.long 0x38000002\n.long 0x90050000\n.long 0x4800000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x38600001\n.long 0x4E800020");
}
