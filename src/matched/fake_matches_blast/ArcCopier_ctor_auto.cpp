// 0x80321430 ArcCopier::ArcCopier (28b)

struct ArcCopier {
    void* m_vt;
    int m_field4;
    int m_field8;
    int m_fieldC;
    
    ArcCopier();
};

ArcCopier::ArcCopier() {
    ArcCopier* p = this;
    *(int**)p = 0;
    p->m_field4 = 0;
    p->m_field8 = 0;
    p->m_fieldC = 0;
}
