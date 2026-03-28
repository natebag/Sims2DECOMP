extern int __vt_NodeAllocChunkHelper[];

int NodeAllocChunkFunc(void *);

struct NodeAllocChunkHelper {
    char pad_00[0x04];
    int* m_vtable;

    int ChunkAllocInit();
};

int NodeAllocChunkHelper::ChunkAllocInit() {
    m_vtable = __vt_NodeAllocChunkHelper;
    return NodeAllocChunkFunc(this);
}
