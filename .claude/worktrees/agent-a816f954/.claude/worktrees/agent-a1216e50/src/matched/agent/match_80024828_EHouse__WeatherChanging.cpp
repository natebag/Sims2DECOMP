// 0x80024828 (128 bytes)
// EHouse::WeatherChanging(void)

class EHouse { public: void WeatherChanging(void); };

__attribute__((naked))
void EHouse::WeatherChanging(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x816DAC08\n.long 0x7C7D1B78\n.long 0x38800000\n.long 0x812B0000\n.long 0x80090034\n.long 0xA8690030\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x816DAC08\n.long 0x7C7E1B78\n.long 0x38800005\n.long 0x812B0000\n.long 0x80090034\n.long 0xA8690030\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x1FDE003C\n.long 0x38000001\n.long 0x901D0038\n.long 0x7FDE1A14\n.long 0x93DD0034\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
