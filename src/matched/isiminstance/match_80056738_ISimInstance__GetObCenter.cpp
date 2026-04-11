// 0x80056738 ISimInstance::GetObCenter (36b)

struct EVec3 {
    float x, y, z;
};

struct ISimInstance {
    char _pad[0x100];
    EVec3 m_obCenter;
};

extern "C" void* ISimInstance_GetObCenter(void* retptr, ISimInstance* self) {
    float* src = (float*)&self->m_obCenter;
    float* dst = (float*)retptr;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    return retptr;
}
