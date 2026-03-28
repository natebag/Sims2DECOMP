extern int __vt_NodeAllocChunkCtor[];

void NodeAllocChunkBase(void *);

struct NodeAllocChunkCtor {
    char pad_00[0x04];
    int* m_vtable;

    NodeAllocChunkCtor();
};

NodeAllocChunkCtor::NodeAllocChunkCtor() {
    NodeAllocChunkBase(this);
    m_vtable = __vt_NodeAllocChunkCtor;
}
