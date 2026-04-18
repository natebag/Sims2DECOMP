// 0x803446F0 (36B) ENgcRenderer::SetRasterModes(EDLEntry *)

struct ENgcR_SRM_Inner {
    char pad1[0x6CC];
    unsigned int m_6CC;
    char pad2[0x1C];
    unsigned int m_6EC;
};

struct ENgcR_SRM {
    char pad[0x4D8];
    ENgcR_SRM_Inner* m_4D8;
    void SetRasterModes(void* entry);
};

void ENgcR_SRM::SetRasterModes(void* entry) {
    unsigned int val = ((unsigned int*)entry)[1];
    ENgcR_SRM_Inner* inner1 = m_4D8;
    inner1->m_6EC = val;
    ENgcR_SRM_Inner* inner2 = m_4D8;
    inner2->m_6CC |= 0x80000040u;
}
