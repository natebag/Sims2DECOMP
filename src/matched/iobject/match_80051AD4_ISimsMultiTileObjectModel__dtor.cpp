/* ISimsMultiTileObjectModel::~ISimsMultiTileObjectModel(void) at 0x80051AD4 (96B) */

struct EAHeap {
    void Free(void *ptr);
};

EAHeap *MainHeap(void);

extern int ISimsMultiTileObjectModel_vtable2[];
extern int ISimsMultiTileObjectModel_vtable[];

void ISimsObjectModel_dtor(void *self, int delFlag);

void ISimsMultiTileObjectModel_dtor(void *self, int delFlag) {
    *(int *)((char *)self + 0x320) = (int)ISimsMultiTileObjectModel_vtable2;
    *(int *)self = (int)ISimsMultiTileObjectModel_vtable;
    ISimsObjectModel_dtor(self, 0);
    if (delFlag & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(self);
    }
}
