// 0x802D5A6C EVec3::Print (60 bytes)
// Printf-thunk template via EORDbgTrace + 3 floats (crset cr1+eq).

extern char gEVec3PrintFormat[256];

extern "C" void EORDbgTrace(const char* fmt, ...);

struct EVec3 {
    float x;
    float y;
    float z;
    void Print();
};

void EVec3::Print() {
    EORDbgTrace(gEVec3PrintFormat, x, y, z);
}
