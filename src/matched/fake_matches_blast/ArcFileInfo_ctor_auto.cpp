// 0x80321724 ArcFileInfo::ArcFileInfo (32b)

struct ArcFileInfo {
    void* m_vt;
    int m_field4;
    int m_field8;
    int m_fieldC;
    int m_field10;
    
    ArcFileInfo();
};

ArcFileInfo::ArcFileInfo() {
    ArcFileInfo* p = this;
    *(int**)p = 0;
    p->m_field4 = 0;
    p->m_field8 = 0;
    p->m_fieldC = 0;
    p->m_field10 = 0;
}
