// FLAGS: -fno-schedule-insns
// 0x8021DFF4 (36B) InteractorModule::SimInteractor::GetInteractorInfo(InteractorModule::InteractorInfo &)

struct InteractorInfo {
    float f0;
    float f1;
    int i0;
    int i1;
};

struct SimInteractor {
    char pad[8];
    float m_f0;
    float m_f1;
    char pad2[64];
    int m_i0;
    int m_i1;
    void GetInteractorInfo(InteractorInfo& out);
};

void SimInteractor::GetInteractorInfo(InteractorInfo& out) {
    out.f0 = m_f0;
    out.f1 = m_f1;
    int a = m_i1;
    int b = m_i0;
    out.i1 = a;
    out.i0 = b;
}
