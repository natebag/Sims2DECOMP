// 0x801D6144 (104 bytes)
// PCTTarget::get_motive_rating_value(unsigned int, unsigned wchar_t *) const

class PCTTarget { public: void get_motive_rating_value(unsigned int, unsigned wchar_t *) const; };

__attribute__((naked))
void PCTTarget::get_motive_rating_value(unsigned int, unsigned wchar_t *) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x549F103A\n.long 0x3BC300D8\n.long 0x7C1EF82E\n.long 0x7CBD2B78\n.long 0x2C000000\n.long 0x4182002C\n.long 0x392300CC\n.long 0x7C69F82E\n.long 0x4BFFB95D\n.long 0x2C030000\n.long 0x40820018\n.long 0x7C7EF82E\n.long 0x7FA4EB78\n.long 0x4BFA1A1D\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
