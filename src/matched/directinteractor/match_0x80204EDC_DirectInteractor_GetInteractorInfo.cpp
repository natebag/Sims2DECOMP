// 0x80204EDC InteractorModule::DirectInteractor::GetInteractorInfo(InteractorModule::InteractorInfo &) (48B)

struct InteractorInfo {
    float x;
    float y;
    int field8;
    int field12;
};

struct DirectInteractor {
    char pad[80];
    int m_field80;
    int m_field84;
    char pad2[32];
    float* m_floats;
    void GetInteractorInfo(InteractorInfo& info);
};

void DirectInteractor::GetInteractorInfo(InteractorInfo& info) {
    float* f = m_floats;
    if (f != 0) {
        info.x = f[0];
        info.y = f[1];
    }
    int b = m_field80;
    int a = m_field84;
    info.field12 = a;
    info.field8 = b;
}
