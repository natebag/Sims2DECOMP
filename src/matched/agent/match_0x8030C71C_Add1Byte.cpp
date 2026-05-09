// 0x8030C71C (36B) Add1Byte(unsigned char *&p, unsigned char val)
// Phantom 16B frame: volatile unsigned char forces stwu -16 + stb r4,8(r1).
// Default scheduling hoists lwz r11 before the stb (hides load latency).

void Add1Byte(unsigned char *&p, unsigned char val) {
    volatile unsigned char _dummy;
    _dummy = val;
    *p = val;
    p++;
}
