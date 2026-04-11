struct StackElem {
    char pad[52];
    short errCode;
};

struct ParamPE {
    int a;
    int b;
};

struct InnerVt {
    char pad[272];
    short deltaErr;
    void (*fnErr)(void *, int);
};

struct Inner {
    void *data;
    InnerVt *vt;
};

struct SubObjVt {
    char pad[264];
    short deltaPE;
    int (*fnPE)(void *, int, int);
};

struct SubObj {
    SubObjVt *vt;
};

struct CastResult {
    char pad[0x3F4];
    SubObj *sub;
};

extern int gErrFlag;

void *TreeSim_dyncast(void *, int);

class cXObjectImpl {
public:
    StackElem *m_elem;
    Inner *m_inner;

    long long TryParticleEffect(StackElem *s, ParamPE *p);
};

long long cXObjectImpl::TryParticleEffect(StackElem *s, ParamPE *p) {
    int pa = p->a;
    int pb = p->b;

    void *castRes;
    if (this) {
        castRes = TreeSim_dyncast(m_inner->data, 7);
    } else {
        castRes = 0;
    }

    if (castRes == 0) {
        gErrFlag = 1;
        m_elem->errCode = 28;

        InnerVt *vt = m_inner->vt;
        short adj = vt->deltaErr;
        void (*fn)(void *, int) = vt->fnErr;
        fn((char *)m_inner + adj, 28);
        return -1;
    }

    CastResult *cr = (CastResult *)castRes;
    SubObj *sub = cr->sub;
    SubObjVt *svt = sub->vt;
    int (*pfn)(void *, int, int) = svt->fnPE;
    short sadj = svt->deltaPE;
    int result = pfn((char *)sub + sadj, pa, pb);
    return (long long)(result == 1);
}
