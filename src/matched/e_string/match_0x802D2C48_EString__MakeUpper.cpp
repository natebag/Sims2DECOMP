/* EString::MakeUpper(void) @ 0x802D2C48 (52 bytes) */

struct EString_MU {
    char* m_buffer;
    EString_MU* MakeUpper();
};

EString_MU* EString_MU::MakeUpper() {
    char* p = m_buffer;
    unsigned char c = *p;
    if (!c) return this;
    do {
        if ((unsigned char)(c - 'a') <= 25)
            *p = (char)(c - 32);
        c = *++p;
    } while (c);
    return this;
}
