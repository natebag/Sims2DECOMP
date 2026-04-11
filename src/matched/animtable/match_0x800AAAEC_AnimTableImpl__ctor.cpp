// 0x800AAAEC AnimTableImpl::AnimTableImpl (28b)

extern int VT_AnimTableImpl[];

struct AnimTableImpl {
    void* vtable;
    int field_4;
    AnimTableImpl();
};

AnimTableImpl::AnimTableImpl() {
    vtable = VT_AnimTableImpl;
    field_4 = 0;
}
