// 0x80132878 PropTableImpl::PropTableImpl(void) (28b)

struct PropTableImplData {
    int pad;
    short m_id;
};

class PropTableImpl {
public:
    void *vtable;
    PropTableImplData *m_data;

    PropTableImpl(void);
};

// Virtual table at 0x80464100
extern void* PropTableImpl_vtable[];

PropTableImpl::PropTableImpl(void) {
    vtable = PropTableImpl_vtable;
    m_data = 0;
}
