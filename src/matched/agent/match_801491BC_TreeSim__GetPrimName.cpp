// 0x801491BC (40 bytes)
// TreeSim::GetPrimName(short)
// DOL: clrlwi r0, r3 (so n is in r3, this is not used → static or n is first param)
// if n > 67 return NULL; else return table[n]

extern const char* g_primNameTable[];  // at 0x8042438C

class TreeSim {
public:
    static const char* GetPrimName(short n);
};

const char* TreeSim::GetPrimName(short n) {
    unsigned int idx = (unsigned int)(unsigned short)n;
    if (idx > 67)
        return 0;
    return g_primNameTable[idx];
}
