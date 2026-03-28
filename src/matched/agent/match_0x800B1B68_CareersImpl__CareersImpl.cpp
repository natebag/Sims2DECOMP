/* CareersImpl::CareersImpl(void) at 0x800B1B68 (20B) */

extern int CareersImpl_vtable[];

struct CareersImpl {
    int* m_vtable;

    CareersImpl(void);
};

CareersImpl::CareersImpl(void) {
    m_vtable = CareersImpl_vtable;
}
