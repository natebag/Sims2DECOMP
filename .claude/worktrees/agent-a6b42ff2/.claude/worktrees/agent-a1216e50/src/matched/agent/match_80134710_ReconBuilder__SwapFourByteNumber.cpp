// 0x80134710 (36 bytes)
class ReconBuilder {
public:
    void SwapFourByteNumber(unsigned int* value);
};

void ReconBuilder::SwapFourByteNumber(unsigned int* value) {
    volatile unsigned char* bytes = (volatile unsigned char*)value;
    register unsigned char b0 __asm__("r10") = bytes[3];
    register unsigned char b1 __asm__("r9") = bytes[0];
    register unsigned char b2 __asm__("r0") = bytes[2];
    register unsigned char b3 __asm__("r11") = bytes[1];
    __asm__ __volatile__("" : "+r"(b0), "+r"(b1), "+r"(b2), "+r"(b3));
    bytes[1] = b2;
    bytes[3] = b1;
    bytes[0] = b0;
    bytes[2] = b3;
}
