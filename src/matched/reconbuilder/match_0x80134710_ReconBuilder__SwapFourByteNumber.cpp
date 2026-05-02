// FLAGS: -fno-schedule-insns
// 0x80134710 ReconBuilder::SwapFourByteNumber(unsigned int *) (36B)

struct ReconBuilder {
    void SwapFourByteNumber(unsigned int *p);
};

void ReconBuilder::SwapFourByteNumber(unsigned int *p) {
    unsigned char *b = (unsigned char *)p;
    unsigned char t3 = b[3];
    unsigned char t0 = b[0];
    unsigned char t2 = b[2];
    unsigned char t1 = b[1];
    b[1] = t2;
    b[3] = t0;
    b[0] = t3;
    b[2] = t1;
}
