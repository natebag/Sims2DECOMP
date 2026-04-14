// 0x802E94A8 EAnimController::GetAnimDistance (48b)

struct EVec3 { float x, y, z; };

extern void GetAnimTranslate(void*, int, EVec3*, EVec3*);
extern float PSVECMag(EVec3*);

float EAnimController_GetAnimDistance(void* self, int flags, EVec3* outVec) {
    EVec3 tmp;
    GetAnimTranslate(self, flags, &tmp, outVec);
    return PSVECMag(&tmp);
}
