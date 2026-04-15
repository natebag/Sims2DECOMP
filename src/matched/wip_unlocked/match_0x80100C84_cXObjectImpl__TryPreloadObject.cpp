struct StackElem;

struct ManagerVt {
    char p0[0x40];
    short a8;
    void (*f8)(void *);
    char p1[0x78 - 0x48];
    short a15;
    void *(*f15)(void *, int);
    char p2[0x160 - 0x80];
    short a44;
    int (*f44)(void *, void *, int);
};

struct Manager {
    ManagerVt *vt;
};

extern Manager *gObjMan;

struct PrimParam {
    int guid;
    unsigned short flags;
};

class cXObjectImpl {
public:
    long long TryPreloadObject(StackElem *s, PrimParam *p);
};

long long cXObjectImpl::TryPreloadObject(StackElem *s, PrimParam *p) {
    unsigned short flags = p->flags;
    Manager *mgr = gObjMan;

    if (flags & 1) {
        ManagerVt *vt = mgr->vt;
        short adj = vt->a8;
        void (*fn)(void *) = vt->f8;
        fn((char *)mgr + adj);
        return 1;
    }

    int guid = p->guid;
    if (guid == 0) {
        return 0;
    }

    ManagerVt *vt = mgr->vt;
    short adj = vt->a15;
    void *(*fn)(void *, int) = vt->f15;
    void *obj = fn((char *)mgr + adj, guid);
    if (!obj) {
        return 0;
    }

    vt = mgr->vt;
    short adj2 = vt->a44;
    int (*fn2)(void *, void *, int) = vt->f44;
    int res = fn2((char *)mgr + adj2, obj, 0);
    if (res != 0) {
        return 1;
    }
    return 2;
}
