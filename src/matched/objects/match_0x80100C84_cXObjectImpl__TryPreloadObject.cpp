// 0x80100C84 (200 bytes) — VERIFIED MATCH
// cXObjectImpl::TryPreloadObject(StackElem *, XPrimParam *)
// Preloads an object resource. Checks flag bit 0, then uses virtual dispatch
// to look up and preload the object definition.

struct StackElem;
struct XPrimParam;

typedef void (*vfn_t)();

struct TPO {
    long long TryPreloadObject(StackElem *elem, XPrimParam *param);
};

extern void *g_objMgr;

long long TPO::TryPreloadObject(StackElem *elem, XPrimParam *param) {
    unsigned short flags = *(unsigned short *)((char *)param + 4);
    char *mgr = (char *)g_objMgr;

    if (flags & 1) {
        char *vt = *(char **)mgr;
        short adj = *(short *)(vt + 64);
        vfn_t fn = (vfn_t)*(void **)(vt + 68);
        ((void (*)(void *))fn)(mgr + adj);
        return 1;
    }

    int data0 = *(int *)param;
    if (data0 == 0) {
        return 0;
    }

    char *vt = *(char **)mgr;
    short adj = *(short *)(vt + 120);
    void *(*fn2)(void *, int) = (void *(*)(void *, int))*(void **)(vt + 124);
    void *result = fn2(mgr + adj, data0);

    if (result == 0) {
        return 0;
    }

    char *vt2 = *(char **)mgr;
    short adj2 = *(short *)(vt2 + 352);
    int (*fn3)(void *, void *, int) = (int (*)(void *, void *, int))*(void **)(vt2 + 356);
    int r = fn3(mgr + adj2, result, 0);

    if (r != 0) {
        return 1;
    }
    return ((long long)0 << 32) | 2;
}
