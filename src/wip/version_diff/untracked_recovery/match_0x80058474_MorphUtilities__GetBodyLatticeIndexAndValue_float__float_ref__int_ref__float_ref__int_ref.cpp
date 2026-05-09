// 0x80058474 (132B) MorphUtilities::GetBodyLatticeIndexAndValue(float, float&, int&, float&, int&)
// Pure leaf with float lattice mapping.

extern float g_latticeZero __attribute__((section(".data")));
extern float g_latticeOne __attribute__((section(".data")));
extern float g_latticeMax;

struct MorphUtilities {
    void GetBodyLatticeIndexAndValue(float value, float& outVal, int& outIdx, float& outDefault, int& outNeg);
};

void MorphUtilities::GetBodyLatticeIndexAndValue(float value, float& outVal, int& outIdx, float& outDefault, int& outNeg) {
    outIdx = 0;
    outNeg = -1;
    outVal = g_latticeZero;
    outDefault = g_latticeZero;
    
    if (value >= g_latticeZero) {
        if (value < g_latticeOne) {
            outIdx = 1;
            outVal = g_latticeOne - value;
            return;
        }
    }
    
    if (value <= g_latticeOne) {
        return;
    }
    if (value >= g_latticeMax) {
        outVal = value - g_latticeOne;
    }
}
