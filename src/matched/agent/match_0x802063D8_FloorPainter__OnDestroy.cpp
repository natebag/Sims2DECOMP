void *FP_GetVis(void);
void FP_DestroyVis(void *, void *);
void FP_ReleaseRes(void *);

struct FP_DestroyS {
    char _pad[0xB8];
    void *m_resource;
    void OnDestroy(void);
};

void FP_DestroyS::OnDestroy(void) {
    void *vis = FP_GetVis();
    FP_DestroyVis(vis, this);
    if (m_resource != 0) {
        FP_ReleaseRes(m_resource);
    }
    m_resource = 0;
}
