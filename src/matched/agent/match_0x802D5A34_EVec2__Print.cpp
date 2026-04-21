// 0x802D5A34 EVec2::Print (56 bytes)
// Printf-thunk template via EORDbgTrace + 2 floats (crset cr1+eq).

extern char gEVec2PrintFormat[256];

extern "C" void EORDbgTrace(const char* fmt, ...);

struct EVec2 {
    float x;
    float y;
    void Print();
};

void EVec2::Print() {
    EORDbgTrace(gEVec2PrintFormat, x, y);
}
