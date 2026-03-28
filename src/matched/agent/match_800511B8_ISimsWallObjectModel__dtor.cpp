/* ISimsWallObjectModel::~ISimsWallObjectModel(void) at 0x800511B8 (96B) */

struct EAHeap {
    void Free(void *ptr);
};

EAHeap *MainHeap(void);

extern int ISimsWallObjectModel_vtable2[];
extern int ISimsWallObjectModel_vtable[];

void ISimsObjectModel_dtor(void *self, int delFlag);

void ISimsWallObjectModel_dtor(void *self, int delFlag) {
    *(int *)((char *)self + 0x320) = (int)ISimsWallObjectModel_vtable2;
    *(int *)self = (int)ISimsWallObjectModel_vtable;
    ISimsObjectModel_dtor(self, 0);
    if (delFlag & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(self);
    }
}
