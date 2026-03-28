/* ReconBuilder::SwapTwoByteNumber(unsigned short *) - 0x801346FC - 20 bytes */
/* lbz r0, 1(r4); lbz r9, 0(r4); stb r0, 0(r4); stb r9, 1(r4); blr */

class ReconBuilder {
public:
    void SwapTwoByteNumber(unsigned short *);
};

void ReconBuilder::SwapTwoByteNumber(unsigned short *p) {
    unsigned char *bytes = (unsigned char *)p;
    unsigned char tmp = bytes[1];
    bytes[1] = bytes[0];
    bytes[0] = tmp;
}
