// PADIsBarrel - 0x80266E10 (60 bytes)
//
// Tech #73 application — channel-bound check + SDA bitmask test.
// 4 return paths: 2 false returns share tail_A (chan<0, chan>=4),
// 1 false return tail_B (bit-test fail), 1 true return.
//
// FLAGS: -msdata=eabi -G 8

extern unsigned int g_padBarrelFlags;

int PADIsBarrel(int chan) {
    if (chan < 0) return 0;
    if (chan >= 4) return 0;
    unsigned int mask = 0x80000000u >> chan;
    if (g_padBarrelFlags & mask) return 1;
    return 0;
}
