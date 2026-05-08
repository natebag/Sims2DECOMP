// 0x800D8A84 NghResFile::SwapFourByteNumber(unsigned int*) (36B)

struct NghResFile {
    void SwapFourByteNumber(unsigned int* p);
};

void NghResFile::SwapFourByteNumber(unsigned int* p) {
    unsigned char* b = (unsigned char*)p;
    unsigned char b3 = *(volatile unsigned char*)&b[3];
    unsigned char b0 = *(volatile unsigned char*)&b[0];
    unsigned char b2 = *(volatile unsigned char*)&b[2];
    unsigned char b1 = *(volatile unsigned char*)&b[1];
    *(volatile unsigned char*)&b[1] = b2;
    *(volatile unsigned char*)&b[3] = b0;
    *(volatile unsigned char*)&b[0] = b3;
    *(volatile unsigned char*)&b[2] = b1;
}
