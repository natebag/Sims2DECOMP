// 0x80368E90 ERDataset::~ERDataset (184B)
// Variant G': EResource + Deallocate body + vector<T_12B>-iter-loop
//             with trivial T dtor + magic-div-128-branch + EResource chain.
//
// Magic constant 0xAAAAAAAB = (3)^-1 mod 2^32 — exact-div-by-3 trick.
// sizeof(T_12B)=12=4*3, so mullw+srawi 2 gives count = bytes/12.
// mulli * 12 recovers bytes for the 128-byte SGI STL allocator branch.

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

class EResource {
public:
    virtual ~EResource();
};

template<bool _T, int _I>
class __node_alloc {
public:
    static void _M_deallocate(void* p, unsigned int n);
};

struct ERDataset_T12 {
    int a, b, c;  // 12-byte POD with trivial dtor
};

struct ERDataset_VecData {
    ERDataset_T12* m_start;          // +0
    ERDataset_T12* m_finish;         // +4
    int m_alloc_pad;                 // +8 (allocator hole)
    ERDataset_T12* m_end_of_storage; // +12
};

class ERDataset : public EResource {
public:
    char m_pad_04_13[0x14 - 4];      // pad from +4 (EResource end) to +20
    ERDataset_VecData m_vec;         // +0x14

    virtual ~ERDataset();
    void Deallocate();
    static void operator delete(void* p);
};

inline void ERDataset::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERDataset::~ERDataset() {
    Deallocate();
    ERDataset_VecData* vec = &m_vec;
    ERDataset_T12* p = vec->m_start;
    while (p != vec->m_finish) {
        ++p;
    }
    if (vec->m_start != 0) {
        unsigned int bytes = (unsigned int)(vec->m_end_of_storage - vec->m_start) * 12;
        if (bytes > 128) {
            ::operator delete(vec->m_start);
        } else {
            __node_alloc<false, 0>::_M_deallocate(vec->m_start, bytes);
        }
    }
}
