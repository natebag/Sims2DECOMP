/* cXMTObjectImpl::GetISimInstanceBaseVer(void) - 40 bytes */

struct TreeSimImpl {
    void *GetISimInstance(void);
};

struct SomeInner {
    TreeSimImpl *m_treeSim;
};

struct cXMTObjectImpl {
    SomeInner *m_inner;

    void *GetISimInstanceBaseVer(void);
};

void *cXMTObjectImpl::GetISimInstanceBaseVer(void) {
    return m_inner->m_treeSim->GetISimInstance();
}
