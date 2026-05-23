// 0x803674EC ERAnim::~ERAnim (196B)
// Variant I': EResource + s_instanceCount SDA decrement at top
//             + 4 TArray<X, TArrayERAnimAllocator>::~TArray member dtors
//             + INLINE ERAnimBitArray member dtor (vtable-chain double-Deallocate)
//             + EResource destruct chain.
//
// Variant I' = base Variant-I + s_instanceCount-SDA + inline-derived-EBitArray-member-dtor.

extern int s_instanceCount;  // SDA-resident counter (-25836(r13)). No map symbol;
                              // R_PPC_EMB_SDA21 reloc gets masked by verify_match.

class EResource {
public:
    virtual ~EResource();
};

class EResourceManager {
public:
    void Free(void* p);
};

extern char g_resourceManager[16];

extern int VT_EBitArray[];
extern int VT_ERAnimBitArray[];

class EBitArray {
public:
    int* m_pBuffer;        // +0x00
    int m_nSize;           // +0x04
    int m_nAllocSize;      // +0x08
    int m_field_C;         // +0x0C
    int* m_vtable;         // +0x10
    void Deallocate();
    inline ~EBitArray() {
        m_vtable = VT_EBitArray;
        Deallocate();
    }
};

class ERAnimBitArray : public EBitArray {
public:
    char m_extra[56 - 20]; // pad to 56B (member spans +0x50 to +0x88 in ERAnim)
    inline ~ERAnimBitArray() {
        m_vtable = VT_ERAnimBitArray;
        Deallocate();
        // ~EBitArray() chain auto
    }
};

class TArrayERAnimAllocator;
class EAnimNodeDataPos;
class EAnimNote;
class EAnimEvent;

template<class T, class Alloc>
class TArray {
public:
    void* m_begin;
    void* m_end;
    void* m_alloc_end;
    ~TArray();
};

class ERAnim : public EResource {
public:
    char m_pad_04_33[0x34 - 4];
    TArray<EAnimNodeDataPos, TArrayERAnimAllocator> m_arr_34; // +0x34
    int m_pad_40;                                              // +0x40 (4B pad)
    TArray<float, TArrayERAnimAllocator> m_arr_44;             // +0x44
    ERAnimBitArray m_bitArray_50;                              // +0x50 (56B)
    TArray<EAnimNote, TArrayERAnimAllocator> m_arr_88;         // +0x88
    TArray<EAnimEvent, TArrayERAnimAllocator> m_arr_94;        // +0x94

    virtual ~ERAnim();
    static void operator delete(void* p);
};

inline void ERAnim::operator delete(void* p) {
    ((EResourceManager*)g_resourceManager)->Free(p);
}

ERAnim::~ERAnim() {
    --s_instanceCount;
    // Member dtors auto-emit in reverse decl order: m_arr_94, m_arr_88,
    // m_bitArray_50 (inlined chain), m_arr_44, m_arr_34.
    // Then EResource::~EResource(this, 0) chain.
}
