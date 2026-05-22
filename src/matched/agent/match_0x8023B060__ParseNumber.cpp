// 0x8023B060 _ParseNumber(uchar*, uint*) (64B)

extern void _ParseNumber(unsigned char* p, unsigned int* result);

void _ParseNumber(unsigned char* p, unsigned int* result) {
    *result = 0;
    unsigned char c = *p;
    unsigned int d = (unsigned int)c - 0x30;
    if (d > 9) return;
    do {
        *result = (*result) * 10 + (c & 0xF);
        ++p;
        c = *p;
        d = (unsigned int)c - 0x30;
    } while (d <= 9);
}
