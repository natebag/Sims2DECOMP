// 0x80318014 (224B) ERModel::~ERModel(void)
// Variant I: EResource SI deleting-dtor + DeallocateScaleMatrix + buffer free
// + 6 TArray<X, TArrayERModelAllocator>::Destruct(2) cleanup chain

class EResourceManager {
public:
    void Free(void* p);
};

extern char g_resourceManager[16];

class EResource {
public:
    virtual ~EResource();
};

class ESubModel;
class SimsLightInfo;
class BSplineVolume;
class ENLattice;
class ENDummy;
class ENCamera;
class TArrayERModelAllocator;

template<class T, class Alloc>
class TArray {
public:
    void* m_begin;
    void* m_end;
    void* m_alloc_end;
    void Destruct(int);
};

class ERModel : public EResource {
public:
    char m_pad_04_3b[0x3c - 4];
    TArray<ESubModel, TArrayERModelAllocator> m_arr_3c;
    char m_pad_48_8f[0x90 - 0x48];
    TArray<SimsLightInfo, TArrayERModelAllocator> m_arr_90;
    char m_pad_9c_103[0x104 - 0x9c];
    TArray<BSplineVolume, TArrayERModelAllocator> m_arr_104;
    TArray<ENLattice, TArrayERModelAllocator> m_arr_110;
    TArray<ENDummy, TArrayERModelAllocator> m_arr_11c;
    TArray<ENCamera, TArrayERModelAllocator> m_arr_128;
    signed char m_byte_134;
    signed char m_byte_135;
    char m_pad_136_137[2];
    int m_field_138;
    void* m_field_13c;

    virtual ~ERModel();
    void DeallocateScaleMatrix(void);
    static void operator delete(void* p);
};

inline void ERModel::operator delete(void* p) {
    ((EResourceManager*)g_resourceManager)->Free(p);
}

ERModel::~ERModel(void) {
    DeallocateScaleMatrix();
    if (m_field_13c != 0) {
        ((EResourceManager*)g_resourceManager)->Free(m_field_13c);
        m_field_13c = 0;
    }
    m_byte_134 = 0;
    m_byte_135 = -1;
    m_field_138 = 0;
    m_arr_128.Destruct(2);
    m_arr_11c.Destruct(2);
    m_arr_110.Destruct(2);
    m_arr_104.Destruct(2);
    m_arr_90.Destruct(2);
    m_arr_3c.Destruct(2);
}
