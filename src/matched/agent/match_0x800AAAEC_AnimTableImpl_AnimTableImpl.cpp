// 0x800AAAEC AnimTableImpl::AnimTableImpl(void) (28b)

struct AnimTableImplData {
    int pad;
    short m_id;
};

class AnimTableImpl {
public:
    void *vtable;
    AnimTableImplData *m_data;

    AnimTableImpl(void);
};

// Virtual table at 0x8046E748
extern void* AnimTableImpl_vtable[];

AnimTableImpl::AnimTableImpl(void) {
    vtable = AnimTableImpl_vtable;
    m_data = 0;
}
