// 0x8036A194 ERSoundTrackData::~ERSoundTrackData (164B)
// Variant G' sibling: EResource + vector<int>-iter-loop with sizeof=4 (trivial T)
//                     + magic-div simplified to 'clrrwi r4, r0, 2' (round to mult of 4)
//                     + 128B SGI STL allocator branch + EResource chain.
//
// sizeof(T)=4 case: pointer subtraction + multiply collapses to 'and ~3' since
// (end-start) for T*=int* gives count, *4 = bytes (always multiple of 4 anyway).

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

struct ERSoundTrackData_VecData {
    int* m_start;          // +0
    int* m_finish;         // +4
    int m_alloc_pad;       // +8
    int* m_end_of_storage; // +12
};

class ERSoundTrackData : public EResource {
public:
    char m_pad_04_13[0x14 - 4];
    ERSoundTrackData_VecData m_vec;   // +0x14

    virtual ~ERSoundTrackData();
    static void operator delete(void* p);
};

inline void ERSoundTrackData::operator delete(void* p) {
    MainHeap()->Free(p);
}

ERSoundTrackData::~ERSoundTrackData() {
    ERSoundTrackData_VecData* vec = &m_vec;
    int* p = vec->m_start;
    while (p != vec->m_finish) {
        ++p;
    }
    if (vec->m_start != 0) {
        unsigned int bytes = (unsigned int)(vec->m_end_of_storage - vec->m_start) * 4;
        if (bytes > 128) {
            ::operator delete(vec->m_start);
        } else {
            __node_alloc<false, 0>::_M_deallocate(vec->m_start, bytes);
        }
    }
}
