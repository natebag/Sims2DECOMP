// 0x80366DC0 ERAmbientScore::~ERAmbientScore (208B)
// Variant G': EResource + raw-ptr field cleanup + vector<ERAmbientSound>-iter-loop
//             with non-trivial T dtor + magic-div-128-branch + EResource chain.
//
// Magic constant 0xC4EC4EC5 = exact-div-by-52 trick.
// sizeof(ERAmbientSound)=52=4*13. mullw+srawi 2 gives count = bytes/52.

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

class ERAmbientSound {
public:
    char m_data[52];
    ~ERAmbientSound();
};

struct ERAmbientScore_VecData {
    ERAmbientSound* m_start;          // +0
    ERAmbientSound* m_finish;         // +4
    int m_alloc_pad;                  // +8
    ERAmbientSound* m_end_of_storage; // +12
};

class ERAmbientScore : public EResource {
public:
    char m_pad_04_1f[0x20 - 4];       // pad to +32
    void* m_field_20;                 // +0x20 — raw pointer (delete at top)
    char m_pad_24_2b[0x2c - 0x24];    // pad to +44
    ERAmbientScore_VecData m_vec;     // +0x2c

    virtual ~ERAmbientScore();
    static void operator delete(void* p);
};

inline void ERAmbientScore::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERAmbientScore::~ERAmbientScore() {
    if (m_field_20 != 0) {
        ::operator delete(m_field_20);
    }
    ERAmbientScore_VecData* vec = &m_vec;
    ERAmbientSound* p = vec->m_start;
    ERAmbientSound* end = vec->m_finish;
    if (p != end) {
        do {
            p->~ERAmbientSound();
            ++p;
        } while (p != end);
    }
    if (vec->m_start != 0) {
        unsigned int bytes = (unsigned int)(vec->m_end_of_storage - vec->m_start) * 52;
        if (bytes > 128) {
            ::operator delete(vec->m_start);
        } else {
            __node_alloc<false, 0>::_M_deallocate(vec->m_start, bytes);
        }
    }
}
