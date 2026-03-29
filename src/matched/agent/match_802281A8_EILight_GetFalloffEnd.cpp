// 0x802281A8 (12 bytes) - EILight::GetFalloffEnd(void)
// lis r9,upper; lfs f1,lower(r9); blr

struct FloatData_FE { float val; int extra[2]; };
extern FloatData_FE EILight_falloffEnd;

float EILight_GetFalloffEnd() {
    return EILight_falloffEnd.val;
}
