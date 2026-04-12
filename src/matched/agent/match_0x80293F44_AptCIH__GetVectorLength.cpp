// 0x80293F44 AptCIH::GetVectorLength (88b)
// FLAGS: -fno-schedule-insns

extern char gAptZeroF[12];
float sqrtf(float);

float AptCIH_GetVectorLength(float *m) {
    float zero = *(float *)gAptZeroF;
    if (m[1] == zero && m[2] == zero) {
        return m[0];
    }
    return sqrtf(m[0] * m[0] + m[1] * m[1]);
}
