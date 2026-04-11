// 0x80056738 ISimInstance::GetObCenter (36b)
// FLAGS: -fno-schedule-insns

typedef float v3f[3];

struct ISimInstance {
    char _pad[0x100];
    v3f m_obCenter;
};

void* ISimInstance_GetObCenter(void* retptr, ISimInstance* self) {
    void* out = retptr;
    float* s = self->m_obCenter;
    float* d = (float*)out;
    float f0 = s[0];
    float f1 = s[1];
    float f2 = s[2];
    d[0] = f0;
    d[1] = f1;
    d[2] = f2;
    return out;
}
