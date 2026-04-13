// 0x8012B528 cXPersonImpl::IsFemale (60B)

typedef int (*DispatchFn)(void*);

struct cXPerson_IF {
    char pad_00[4];
    void* m_inner;
    int IsFemale();
};

int cXPerson_IF::IsFemale() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x200);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x204);
    int result = fn(inner + adj);
    return result ^ 1;
}
