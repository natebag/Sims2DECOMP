// 0x801491BC TreeSim::GetPrimName(short) (40 B)

extern const char* g_primNameTable[];

class TreeSim {
public:
    static const char* GetPrimName(short n);
};

const char* TreeSim::GetPrimName(short n) {
    if ((unsigned short)n > 67)
        return 0;
    return g_primNameTable[n];
}
