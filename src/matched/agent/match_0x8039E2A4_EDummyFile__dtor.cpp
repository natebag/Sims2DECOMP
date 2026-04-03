// EDummyFile::~EDummyFile - deleting destructor that calls parent dtor

extern void EFile_dtor(void *self, int flags);

struct EAHeap {
    void Free(void *p);
};

extern EAHeap *MainHeap(void);

struct EDummyFile {
    void dtor_fn(int flags);
};

void EDummyFile::dtor_fn(int flags) {
    EFile_dtor(this, 0);
    if (flags & 1) {
        EAHeap *heap = MainHeap();
        heap->Free(this);
    }
}
