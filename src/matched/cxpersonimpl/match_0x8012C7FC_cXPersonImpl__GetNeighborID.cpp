// 0x8012C7FC cXPersonImpl::GetNeighborID (60B)

typedef void* (*DispatchFn)(void*, int);

struct cXPerson_GNI {
    char pad_00[4];
    void* m_inner;
    void* GetNeighborID() const;
};

void* cXPerson_GNI::GetNeighborID() const {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x138);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x13C);
    return fn(inner + adj, 0x1F);
}
