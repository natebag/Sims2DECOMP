// 0x802F2204 (12 bytes) - EGraphics::GetFarZVal(void)
// lis r9,upper; lfs f1,lower(r9); blr

struct FloatData_FZ { float val; int extra[2]; };
extern FloatData_FZ EGraphics_farZVal;

float EGraphics_GetFarZVal() {
    return EGraphics_farZVal.val;
}
