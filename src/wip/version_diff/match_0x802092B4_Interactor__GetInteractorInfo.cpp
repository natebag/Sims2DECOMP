/* InteractorModule::Interactor::GetInteractorInfo(InteractorModule::InteractorInfo &) at 0x802092B4 (36B) */

struct InteractorInfo {
    float m_f0;
    float m_f1;
    int m_i0;
    int m_i1;
};

struct Interactor_GII {
    char pad[8];
    float m_fA;
    float m_fB;
    char pad2[0x50 - 0x10];
    int m_iA;
    int m_iB;
    void GetInteractorInfo(InteractorInfo& info);
};

void Interactor_GII::GetInteractorInfo(InteractorInfo& info) {
    info.m_f0 = m_fA;
    info.m_f1 = m_fB;
    int vB = m_iB;
    int vA = m_iA;
    info.m_i1 = vB;
    info.m_i0 = vA;
}
