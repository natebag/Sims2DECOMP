// 0x802D5A6C EVec3::Print (60 bytes)
// DOL: prologue; mr r9,r3; lfs f3,8(r9); lis/addi r3,format; lfs f1,0(r9); lfs f2,4(r9);
//       crset 4*cr1+eq (FP in varargs); bl EORDbgTrace; epilogue.

extern char gEVec3PrintFormat[256];

extern "C" void EORDbgTrace(const char* fmt, ...);

struct EVec3 {
    float x;
    float y;
    float z;
};

extern "C" void EVec3_Print(EVec3* this_) {
    EORDbgTrace(gEVec3PrintFormat, this_->x, this_->y, this_->z);
}
