extern unsigned int s_rngState;

int GetNextRandomNumber() {
    unsigned int state = s_rngState;
    unsigned short lo = (unsigned short)state;
    unsigned short hi = (unsigned short)(state >> 16);
    s_rngState = state * 0x41C64E6Du + 0x3039u;
    unsigned int c1 = ((unsigned int)lo * 0x4E6Du + 0x3039u) >> 16;
    unsigned int c2 = (unsigned int)lo * 0x41C6u;
    unsigned int c3 = (unsigned int)hi * 0x4E6Du;
    unsigned int c4 = ((unsigned int)hi * 0x41C6u & 0xFFFFu) << 16;
    return (int)(c1 + c2 + c3 + c4);
}
