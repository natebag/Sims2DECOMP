// 0x80034FBC (92 bytes)
/* ESimShadow::~ESimShadow(void) */

extern void ESimShadow_virtual_table[];
extern void MainHeap(void);
extern void EAHeap__Free(void *p);

/* EIStaticModel non-deleting base dtor */
extern void EIStaticModel_dtor(void *self, int flags);

struct ESimShadow {
    void *m_vtable;      /* 0x000 */
    char pad_004[0x31C];
    int m_field_320;     /* 0x320 */

    void dtor_fn(int flags);
};

void ESimShadow::dtor_fn(int flags) {
    m_field_320 = 0;
    m_vtable = ESimShadow_virtual_table;
    EIStaticModel_dtor(this, 0);
    if (flags & 1) {
        MainHeap();
        EAHeap__Free(this);
    }
}
