// ISimInstance::~ISimInstance(void)
// Address: 0x80056424 | Size: 328 bytes
// GCC 2.95: dtor takes (this=r3, __in_chrg=r4)
// Key insight: zeroing of f3bc/f3c0 happens AFTER their if-blocks (unconditionally)
// but the if-blocks check the pointer again after RemoveLight

void ERLevel__RemoveLight_fn(void *lvl, void *light);   // 0x80233308
void EAnimController__dtor_fn(void *self, int f);       // 0x802E7884
void IBaseSimInstance__dtor_fn(void *self, int f);      // 0x80056220
void EIStaticModel__dtor_fn(void *self, int f);         // 0x8022BA50
void *MainHeap_fn(void);                                // 0x802CFF00
void EAHeap__Free_fn(void *h, void *p);                 // 0x802D0D78

extern int ISimInstance_vtable[];
extern int ISimInstance_IBaseSimInstance_vtable[];

typedef void *(*vfnE0_t)(void *);
typedef void (*vfn30_t)(void *, int);

struct ISimInstance_dtor_type;

void ISimInstance_dtor_fn(ISimInstance_dtor_type *self, int __in_chrg) {
    char *thiz = (char *)self;

    *(int **)(thiz + 0x320) = ISimInstance_IBaseSimInstance_vtable;
    *(int **)thiz = ISimInstance_vtable;

    if (*(int *)(thiz + 0x328) != 0) {
        *(int *)(thiz + 0x328) = 0;
    }

    // f3bc block: load once, call E0, RemoveLight, check again, call 30/34, then zero
    // DOL structure: outer if -> E0 call + RemoveLight + inner if + (unconditional) zero
    // But wait: DOL has 'load f3c0 BEFORE the zero' - meaning zero is interleaved

    // Re-examining DOL at 0x00BC-0x0A0:
    // 0x09C: lwz r11, 0x3C0(r31)   <- loads f3c0 BEFORE zeroing f3bc
    // 0x0A0: li r0, 0
    // 0x0A4: stw r0, 0x3BC(r31)    <- zeros f3bc AFTER loading f3c0
    // This means: load f3c0, then zero f3bc, then check/handle f3c0

    void *f3bc = *(void **)(thiz + 0x3BC);
    if (f3bc != 0) {
        int *vt = *(int **)f3bc;
        short a = *(short *)((char *)vt + 0xE0);
        vfnE0_t fn = (vfnE0_t)*(void **)((char *)vt + 0xE4);
        void *lvl = fn((char *)f3bc + a);
        ERLevel__RemoveLight_fn(lvl, *(void **)(thiz + 0x3BC));
        f3bc = *(void **)(thiz + 0x3BC);
        if (f3bc != 0) {
            int *vt2 = *(int **)f3bc;
            short a2 = *(short *)((char *)vt2 + 0x30);
            vfn30_t fn2 = (vfn30_t)*(void **)((char *)vt2 + 0x34);
            fn2((char *)f3bc + a2, 3);
        }
    }
    // Load f3c0 BEFORE zeroing f3bc (DOL has this ordering)
    void *f3c0 = *(void **)(thiz + 0x3C0);
    *(int *)(thiz + 0x3BC) = 0;

    if (f3c0 != 0) {
        int *vt = *(int **)f3c0;
        short a = *(short *)((char *)vt + 0xE0);
        vfnE0_t fn = (vfnE0_t)*(void **)((char *)vt + 0xE4);
        void *lvl = fn((char *)f3c0 + a);
        ERLevel__RemoveLight_fn(lvl, *(void **)(thiz + 0x3C0));
        f3c0 = *(void **)(thiz + 0x3C0);
        if (f3c0 != 0) {
            int *vt2 = *(int **)f3c0;
            short a2 = *(short *)((char *)vt2 + 0x30);
            vfn30_t fn2 = (vfn30_t)*(void **)((char *)vt2 + 0x34);
            fn2((char *)f3c0 + a2, 3);
        }
    }
    *(int *)(thiz + 0x3C0) = 0;

    EAnimController__dtor_fn(thiz + 0x334, 2);
    IBaseSimInstance__dtor_fn(thiz + 0x320, 0);
    EIStaticModel__dtor_fn(self, 0);

    if (__in_chrg & 1) {
        EAHeap__Free_fn(MainHeap_fn(), self);
    }
}
