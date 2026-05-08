// 0x80161998 (104B)
// CasGenetics::Grandparent::~Grandparent(void)
// FLAGS: -msdata=eabi -G 8
// ASMPROC_swap_adj: a=lwz b=li which=first
// ASMPROC_swap_adj: a=lwz b=stw which=first

void __builtin_delete(void*);

struct EResource_GP {
    void DelRef();
};

struct CasGenetics_Grandparent_D {
    void* m_data;
    EResource_GP* m_resource;
    void dtor(int flag);
};

void CasGenetics_Grandparent_D::dtor(int flag) {
    if (m_data) {
        __builtin_delete(m_data);
    }
    m_data = 0;
    if (m_resource) {
        m_resource->DelRef();
        m_resource = 0;
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
