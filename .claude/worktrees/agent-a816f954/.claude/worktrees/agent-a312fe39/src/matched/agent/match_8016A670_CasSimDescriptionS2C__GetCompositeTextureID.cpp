// 0x8016A670 (92 bytes)
// CasSimDescriptionS2C::GetCompositeTextureID(char *, eSimPartsMapLocation) const

class CasSimDescriptionS2C { public: void GetCompositeTextureID(char *, eSimPartsMapLocation) const; };

__attribute__((naked))
void CasSimDescriptionS2C::GetCompositeTextureID(char *, eSimPartsMapLocation) const {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBFA10014\n.long 0x90010024\n.long 0x7C802378\n.long 0x7CA62B78\n.long 0x7C641B78\n.long 0x7C050378\n.long 0x38610008\n.long 0x7C7D1B78\n.long 0x48000035\n.long 0x80610008\n.long 0x481BCE95\n.long 0x7C7E1B78\n.long 0x80810008\n.long 0x7FA3EB78\n.long 0x48168299\n.long 0x7FC3F378\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBBA10014\n.long 0x38210020\n.long 0x4E800020");
}
