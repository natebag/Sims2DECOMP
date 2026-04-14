// 0x803C336C E3DWindow::~E3DWindow (72B)

extern void EFile_dtor(void *self, int flags);

struct EAHeap {
    void Free(void *p);
};

extern EAHeap *MainHeap(void);

struct E3DWindow {
    void dtor_fn(int flags);
};

void E3DWindow::dtor_fn(int flags) {
    EFile_dtor(this, 0);
    if (flags & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(this);
    }
}
