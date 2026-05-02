// 0x800BCA8C (120B) IconGroupImpl::~IconGroupImpl(void)
// Variant K: vtable@+0 + virtual call on m_8 (slot 3) + vtable@+0 transition + delete branch.

extern char vt_IconGroupImpl_a[];
extern char vt_IconGroupImpl_b[];

void __builtin_delete(void* p);

class IconBase {
public:
    virtual ~IconBase();
    virtual void f1();
    virtual void Cleanup();
};

struct IconGroupImpl {
    void* m_vt_at_0;
    char pad_4_7[4];
    IconBase* m_icon;
    void dtor(int flag);
};

void IconGroupImpl::dtor(int flag) {
    m_vt_at_0 = vt_IconGroupImpl_a;
    if (m_icon != 0) {
        m_icon->Cleanup();
    }
    m_vt_at_0 = vt_IconGroupImpl_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
