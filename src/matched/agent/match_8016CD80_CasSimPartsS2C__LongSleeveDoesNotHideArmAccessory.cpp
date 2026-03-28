// 0x8016CD80 (88 bytes)
// CasSimPartsS2C::LongSleeveDoesNotHideArmAccessory(eBodyPartS2C, unsigned int) const

class CasSimPartsS2C { public: void LongSleeveDoesNotHideArmAccessory(eBodyPartS2C, unsigned int) const; };

__attribute__((naked))
void CasSimPartsS2C::LongSleeveDoesNotHideArmAccessory(eBodyPartS2C, unsigned int) const {
    asm volatile(".long 0x2C04000B\n.long 0x41820010\n.long 0x2C04000E\n.long 0x41820030\n.long 0x48000024\n.long 0x81630004\n.long 0x1D450068\n.long 0x38600001\n.long 0x812B000C\n.long 0x7D295214\n.long 0x88090030\n.long 0x2C000000\n.long 0x4C820020\n.long 0x38600000\n.long 0x4E800020\n.long 0x81630004\n.long 0x1D450064\n.long 0x38600001\n.long 0x812B0010\n.long 0x7D295214\n.long 0x8809001E\n.long 0x4BFFFFD8");
}
