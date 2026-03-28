// 0x80078B74 (92 bytes)
// CUnlockDisplay::SetDirectLight(float, float, float, int)

class CUnlockDisplay { public: void SetDirectLight(float, float, float, int); };

__attribute__((naked))
void CUnlockDisplay::SetDirectLight(float, float, float, int) {
    asm volatile(".long 0x9421FFE8\n.long 0x2C040003\n.long 0x4181004C\n.long 0x80030440\n.long 0x39240001\n.long 0x7C090000\n.long 0x40810008\n.long 0x91230440\n.long 0xD0210008\n.long 0x39210008\n.long 0x1D640018\n.long 0xD0490004\n.long 0xD0690008\n.long 0x80E90004\n.long 0x81010008\n.long 0x80090008\n.long 0x7D6B1A14\n.long 0x394B0360\n.long 0x910B0360\n.long 0x900A0008\n.long 0x90EA0004\n.long 0x38210018\n.long 0x4E800020");
}
