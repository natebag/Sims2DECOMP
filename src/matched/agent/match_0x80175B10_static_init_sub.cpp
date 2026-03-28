extern int __vt_StaticInitHelper[];

int StaticInitFunc(void *);

struct StaticInitHelper {
    char pad_00[0x84];
    int* m_vtable;

    int Init();
};

int StaticInitHelper::Init() {
    m_vtable = __vt_StaticInitHelper;
    return StaticInitFunc(this);
}
