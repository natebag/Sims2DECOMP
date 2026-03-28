// 0x8016AD14 (72 bytes)
// CasSimPartsS2C::GetNumTattooTextures(eTattooTextureTypeS2C) const

class CasSimPartsS2C { public: void GetNumTattooTextures(eTattooTextureTypeS2C) const; };

__attribute__((naked))
void CasSimPartsS2C::GetNumTattooTextures(eTattooTextureTypeS2C) const {
    asm volatile(".long 0x9421FDA0\n.long 0x7C0802A6\n.long 0x90010264\n.long 0x80030004\n.long 0x2C000000\n.long 0x41820020\n.long 0x2C040002\n.long 0x41810018\n.long 0x2C040000\n.long 0x41800010\n.long 0x38A10008\n.long 0x48002649\n.long 0x48000008\n.long 0x38600000\n.long 0x80010264\n.long 0x7C0803A6\n.long 0x38210260\n.long 0x4E800020");
}
