// 0x8016A824 (108 bytes)
// CasSimDescriptionS2C::GetHairBodyPart(void)

class CasSimDescriptionS2C { public: void GetHairBodyPart(void); };

__attribute__((naked))
void CasSimDescriptionS2C::GetHairBodyPart(void) {
    asm volatile(".long 0x80030094\n.long 0x2C000000\n.long 0x4182000C\n.long 0x38600003\n.long 0x4E800020\n.long 0x80630090\n.long 0x2C030001\n.long 0x41820030\n.long 0x41810010\n.long 0x2C030000\n.long 0x4182001C\n.long 0x48000038\n.long 0x2C030002\n.long 0x41820020\n.long 0x2C030003\n.long 0x41820020\n.long 0x48000024\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600004\n.long 0x4E800020\n.long 0x38600005\n.long 0x4E800020\n.long 0x38600006\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020");
}
