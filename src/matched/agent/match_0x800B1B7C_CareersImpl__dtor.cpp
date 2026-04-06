// 0x800B1B7C CareersImpl::~CareersImpl (88b)

extern int VTable_CareersImpl[];
extern void Careers_dtor(void*, int);

struct CareersImpl {
    int* vtable;

    void TearDown();
    ~CareersImpl();
};

CareersImpl::~CareersImpl() {
    vtable = VTable_CareersImpl;
    TearDown();
    Careers_dtor(this, 0);
}
