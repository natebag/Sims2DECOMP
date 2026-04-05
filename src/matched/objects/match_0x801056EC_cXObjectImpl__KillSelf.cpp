// 0x801056EC (148 bytes) — [VERSION_DIFF]
// cXObjectImpl::KillSelf(bool)
// Kills the current object. Dispatches virtual call on field88 interface,
// then does a dynamic cast to TreeSim and notifies the global manager.
// NON_MATCHING: v3.93 generates shared epilogues (branches to 0x90,0xa8,0xd8
// past function body) while DOL v1.76 inlines all code. Also missing mr r4,r3
// after dyncast (v3.93 keeps result in r3, v1.76 moves to r4).
// DOL=148B, compiled=144B (1 instruction fewer: no mr r4,r3).

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
