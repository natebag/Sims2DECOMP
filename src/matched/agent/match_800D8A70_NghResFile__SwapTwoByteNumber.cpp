/* NghResFile::SwapTwoByteNumber(unsigned short *) - 0x800D8A70 (20 bytes) */

struct NghResFile {
    void SwapTwoByteNumber(unsigned short *p);
};

void NghResFile::SwapTwoByteNumber(unsigned short *p) {
    unsigned char *b = (unsigned char *)p;
    unsigned char hi = b[1];
    unsigned char lo = b[0];
    b[0] = hi;
    b[1] = lo;
}
