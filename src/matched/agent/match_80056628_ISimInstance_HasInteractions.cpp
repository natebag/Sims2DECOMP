struct InteractionList {
    InteractionList(void);
    ~InteractionList(void);
    void clear(void);
    int size(void) const;
};

struct cXObject;

extern void CollectInteractionsForObject(cXObject *, InteractionList &, int, int);
extern int rand(void);

extern int _framecount;

struct cSimulator {
    virtual ~cSimulator();
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual void _v6();
    virtual void _v7();
    virtual void _v8();
    virtual void _v9();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual void _v13();
    virtual void _v14();
    virtual int IsStalled();
};

namespace Globs {
    extern cSimulator *pSimulator;
}

class ISimInstance {
public:
    char _pad_000[0x328];
    cXObject *m_xob;
    char _pad_32C[0x80];
    int m_interactTimer[2];
    int m_interactCache[2];

    cXObject *GetXOb(void);
    int HasInteractions(int type);
};

int ISimInstance::HasInteractions(int type) {
    cXObject *xob = GetXOb();
    int result;

    if (Globs::pSimulator->IsStalled() != 0 || m_interactTimer[type] > _framecount) {
        result = m_interactCache[type];
    } else {
        InteractionList list;
        list.clear();

        int *vtbl = *(int **)((char *)xob + 4);
        short adj = *(short *)((char *)vtbl + 608);
        int (*fn)(void *, int) = (int (*)(void *, int))*(void **)((char *)vtbl + 612);
        int gd = fn((char *)xob + adj, 34);

        if (gd == 0) {
            CollectInteractionsForObject(xob, list, type, 1);
        }

        result = 0;
        if (list.size() != 0) {
            result = 1;
        }

        m_interactCache[type] = result;

        int r = rand();
        int rval = (r & 0xF) + 10;
        m_interactTimer[type] = _framecount + rval;
    }

    return result;
}
