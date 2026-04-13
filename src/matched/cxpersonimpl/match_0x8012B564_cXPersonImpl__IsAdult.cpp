// 0x8012B564 cXPersonImpl::IsAdult (60B)

typedef void (*DispatchFn)(void*);

struct cXPerson_IA {
    char pad_00[4];
    void* m_inner;
    int IsAdult();
};

int cXPerson_IA::IsAdult() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x150);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x154);
    fn(inner + adj);
    return 1;
}
