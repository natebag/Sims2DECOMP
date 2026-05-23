// cXObjectImpl::GetRootObject(FTilePt&, int) at 0x800DCA2C (160B)

struct FTilePt { int x; int y; };

struct cXObject;
struct cXObjectImpl;

struct GRVt1 { char pad[592]; short m_off; char _p[2]; void *(*m_fn)(void *, void *); };
struct GRInner1 { GRVt1 *m_vt; };

struct GRVt2 { char pad[1160]; short m_off; char _p[2]; cXObject *(*m_fn)(void *, void *); };
struct GRSubBase { char pad[4]; GRVt2 *m_vt; };
struct GRInner2 { char pad[4]; GRSubBase *m_sub; };

struct CTilePt {
    int data[2];
    CTilePt(FTilePt &, int);
    ~CTilePt();
};

extern GRInner1 *g_rootMgr;

struct cXObjectImpl {
    cXObject *GetRootObject(FTilePt &, int);
};

cXObject *cXObjectImpl::GetRootObject(FTilePt &arg1, int arg2) {
    CTilePt local(arg1, arg2);
    GRInner1 *mgr = g_rootMgr;
    void *result = mgr->m_vt->m_fn((char *)mgr + mgr->m_vt->m_off, &local);
    if (result == 0) {
        return 0;
    }
    GRInner2 *self2 = (GRInner2 *)this;
    GRSubBase *sub = self2->m_sub;
    return sub->m_vt->m_fn((char *)sub + sub->m_vt->m_off, result);
}
