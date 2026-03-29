// 0x802F2210 (12 bytes) - EGraphics::GetNearZVal(void)
// lis r9,upper; lfs f1,lower(r9); blr

struct FloatData_NZ { float val; int extra[2]; };
extern FloatData_NZ EGraphics_nearZVal;

float EGraphics_GetNearZVal() {
    return EGraphics_nearZVal.val;
}
