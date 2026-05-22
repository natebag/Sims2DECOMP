// FLAGS: -fno-schedule-insns
// 0x800D8A84 NghResFile::SwapFourByteNumber(unsigned int *) (36B)

struct NghResFile {
    void SwapFourByteNumber(unsigned int* ptr);
};

void NghResFile::SwapFourByteNumber(unsigned int* ptr) {
    unsigned char* p = (unsigned char*)ptr;
    unsigned char b3 = p[3];
    unsigned char b0 = p[0];
    unsigned char b2 = p[2];
    unsigned char b1 = p[1];
    p[1] = b2;
    p[3] = b0;
    p[0] = b3;
    p[2] = b1;
}
