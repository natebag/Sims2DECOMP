// 0x8014A544 RotateWallBits(unsigned char, int) (28B)

unsigned char RotateWallBits(unsigned char b, int n) {
    int hi = (b << 4) | b;
    int shift = (8 - n) >> 1;
    return (unsigned char)(hi >> shift);
}
