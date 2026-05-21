// 0x8022E3F8 EIStaticSubModel::~EIStaticSubModel(void) (100B)

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

class EInstance {
public:
    virtual ~EInstance();
};

class EIStaticSubModel : public EInstance {
    int m_field4;
public:
    void Deallocate();
    static void operator delete(void* p) { MainHeap()->Free(p); }
    ~EIStaticSubModel();
};

EIStaticSubModel::~EIStaticSubModel() {
    Deallocate();
    m_field4 = 0;
}
