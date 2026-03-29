// 0x802F222C (12 bytes) - EGraphics::GetScreenAspect(void)
// lis r9,upper; lfs f1,lower(r9); blr

struct FloatData_SA { float val; int extra[2]; };
extern FloatData_SA EGraphics_screenAspect;

float EGraphics_GetScreenAspect() {
    return EGraphics_screenAspect.val;
}
