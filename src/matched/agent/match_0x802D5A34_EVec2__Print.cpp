// 0x802D5A34 EVec2::Print (56 bytes)
// DOL: prologue; mr r9,r3; lfs f2,4(r9); lis/addi r3,format; lfs f1,0(r9);
//       crset 4*cr1+eq (FP in varargs); bl EORDbgTrace; epilogue.

extern char gEVec2PrintFormat[256];

extern "C" void EORDbgTrace(const char* fmt, ...);

struct EVec2 {
    float x;
    float y;
};

extern "C" void EVec2_Print(EVec2* this_) {
    EORDbgTrace(gEVec2PrintFormat, this_->x, this_->y);
}
