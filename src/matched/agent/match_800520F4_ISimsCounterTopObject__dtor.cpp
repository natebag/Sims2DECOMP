/* ISimsCounterTopObject::~ISimsCounterTopObject(void) at 0x800520F4 (96B) */

struct EAHeap {
    void Free(void *ptr);
};

EAHeap *MainHeap(void);

extern int ISimsCounterTopObject_vtable2[];
extern int ISimsCounterTopObject_vtable[];

void ISimsObjectModel_dtor(void *self, int delFlag);

void ISimsCounterTopObject_dtor(void *self, int delFlag) {
    *(int *)((char *)self + 0x320) = (int)ISimsCounterTopObject_vtable2;
    *(int *)self = (int)ISimsCounterTopObject_vtable;
    ISimsObjectModel_dtor(self, 0);
    if (delFlag & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(self);
    }
}
