// 0x80344698 (44B) ENgcRenderer::EnableRasterModes(EDLEntry *)

struct ENgcR_ERM_Inner {
    char pad1[0x6CC];
    unsigned int m_6CC;
    char pad2[0x1C];
    unsigned int m_6EC;
};

struct ENgcR_ERM {
    char pad[0x4D8];
    ENgcR_ERM_Inner* m_4D8;
    void EnableRasterModes(void* entry);
};

void ENgcR_ERM::EnableRasterModes(void* entry) {
    ENgcR_ERM_Inner* inner1 = m_4D8;
    inner1->m_6EC |= ((unsigned int*)entry)[1];
    ENgcR_ERM_Inner* inner2 = m_4D8;
    inner2->m_6CC |= 0x80000040u;
}
