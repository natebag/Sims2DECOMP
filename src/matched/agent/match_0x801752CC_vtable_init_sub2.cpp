extern int __vt_VTableInitHelper2[];

void VTableInitFunc2(void *);

struct VTableInitHelper2 {
    char pad_00[0x110];
    int* m_vtable;

    void Init(int flag);
};

void VTableInitHelper2::Init(int flag) {
    m_vtable = __vt_VTableInitHelper2;
    if (flag & 1) {
        VTableInitFunc2(this);
    }
}
