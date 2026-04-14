/* IShrubObject::~IShrubObject(void) at 0x8005262C (96B) */

struct EAHeap {
    void Free(void *ptr);
};

EAHeap *MainHeap(void);

extern int IShrubObject_vtable2[];
extern int IShrubObject_vtable[];

void ISimsObjectModel_dtor(void *self, int delFlag);

void IShrubObject_dtor(void *self, int delFlag) {
    *(int *)((char *)self + 0x320) = (int)IShrubObject_vtable2;
    *(int *)self = (int)IShrubObject_vtable;
    ISimsObjectModel_dtor(self, 0);
    if (delFlag & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(self);
    }
}
