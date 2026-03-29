extern unsigned int srandSeed;

unsigned int GetNextRandomNumber(void) {
    unsigned int seed = srandSeed;
    unsigned int lo = seed & 0xFFFF;
    unsigned int hi = seed >> 16;

    srandSeed = seed * 0x41C64E6Du + 0x3039u;

    return ((lo * 0x4E6Du + 0x3039u) >> 16) + lo * 0x41C6u + hi * 0x4E6Du + ((hi * 0x41C6u) << 16);
}
