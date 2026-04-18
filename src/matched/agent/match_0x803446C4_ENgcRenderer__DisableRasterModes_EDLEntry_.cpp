// 0x803446C4 (44B) ENgcRenderer::DisableRasterModes(EDLEntry *)

struct ENgcR_DRM_Inner {
    char pad1[0x6CC];
    unsigned int m_6CC;
    char pad2[0x1C];
    unsigned int m_6EC;
};

struct ENgcR_DRM {
    char pad[0x4D8];
    ENgcR_DRM_Inner* m_4D8;
    void DisableRasterModes(void* entry);
};

void ENgcR_DRM::DisableRasterModes(void* entry) {
    ENgcR_DRM_Inner* inner1 = m_4D8;
    inner1->m_6EC &= ((unsigned int*)entry)[1];
    ENgcR_DRM_Inner* inner2 = m_4D8;
    inner2->m_6CC |= 0x80000040u;
}
