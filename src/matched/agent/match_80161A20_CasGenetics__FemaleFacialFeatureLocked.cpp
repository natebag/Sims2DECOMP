// 0x80161A20 (76 bytes)
// CasGenetics::FemaleFacialFeatureLocked(signed char)

class CasGenetics { public: void FemaleFacialFeatureLocked(signed char); };

__attribute__((naked))
void CasGenetics::FemaleFacialFeatureLocked(signed char) {
    asm volatile(".long 0x3804FFFA\n.long 0x28000001\n.long 0x40810034\n.long 0x2C040009\n.long 0x4182002C\n.long 0x2C04000A\n.long 0x41820024\n.long 0x2C04000C\n.long 0x4182001C\n.long 0x2C04000D\n.long 0x41820014\n.long 0x2C04000E\n.long 0x4182000C\n.long 0x2C04000F\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
