extern int __vt_VTableInitHelper1[];

void VTableInitFunc1(void *);

struct VTableInitHelper1 {
    char pad_00[0x04];
    int* m_vtable;

    void Init(int flag);
};

void VTableInitHelper1::Init(int flag) {
    m_vtable = __vt_VTableInitHelper1;
    if (flag & 1) {
        VTableInitFunc1(this);
    }
}
