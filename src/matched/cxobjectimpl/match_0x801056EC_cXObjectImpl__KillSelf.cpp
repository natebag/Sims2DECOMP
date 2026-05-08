// 0x801056EC cXObjectImpl::KillSelf(bool) (148B)
// ASMPROC_insert_mr: after="bl TreeSim_dyncastimpl" src=3 dst=4 relabel=3:4 until=g_objModule
//
// S14 Phase 2 wall crack: insert_mr with relabel cascade for branch-convergence
// register pinning. DOL allocates dyncast result to r4 explicitly via `mr r4, r3`
// after the bl, then keeps the else-branch zero in r4 (`li 4, 0`) so the cmpwi
// compares r4. cc1plus picks the natural return-reg r3 and never moves it,
// producing 1 instruction fewer (no mr) and r3-based cmpwi.
//
// Recipe:
//   1. insert_mr injects `mr 4, 3` after the dyncast bl.
//   2. relabel=3:4 cascades through the convergence block (li 3,0 → li 4,0;
//      cmpwi 3,0 → cmpwi 4,0).
//   3. until=g_objModule stops the cascade BEFORE the SDA load (`lwz 3,
//      _g_objModule@sda21(13)`) so the post-cmpwi notify call keeps r3.
//
// New use-case for insert_mr: "preserve return value across branch convergence"
// (canonical case is "free up register before loop body").

typedef void (*vfn_t)();

extern void *g_objModule;

void *TreeSim_dyncastimpl(void *, int);

struct KSelf {
    void KillSelf(bool killFlag);
};

void KSelf::KillSelf(bool killFlag) {
    char *iface = *(char **)((char *)this + 88);
    short sourceID = *(short *)((char *)this + 100);
    char *vt = *(char **)iface;
    short adj = *(short *)(vt + 96);
    vfn_t fn = (vfn_t)*(void **)(vt + 100);
    ((void (*)(void *, short, bool))fn)(iface + adj, sourceID, killFlag);

    void *treeSim;
    if (this != 0) {
        char *field4 = *(char **)((char *)this + 4);
        void *ptr = *(void **)field4;
        treeSim = TreeSim_dyncastimpl(ptr, 2);
    } else {
        treeSim = 0;
    }

    if (treeSim != 0) {
        char *mgr = (char *)g_objModule;
        char *vt2 = *(char **)mgr;
        short adj2 = *(short *)(vt2 + 240);
        vfn_t fn2 = (vfn_t)*(void **)(vt2 + 244);
        ((void (*)(void *))fn2)(mgr + adj2);
    }
}
