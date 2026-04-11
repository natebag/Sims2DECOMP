// 0x800B1B68 CareersImpl::CareersImpl (20b)

extern int CareersImpl_vtable[];

struct CareersImpl {
    int* m_vt;
    CareersImpl();
};

CareersImpl::CareersImpl() {
    *(int**)this = CareersImpl_vtable;
}
