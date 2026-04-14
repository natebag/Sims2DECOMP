// 0x803A6178 SimpleReconObject<NeighborhoodImpl>::DoStream(ReconBuffer*, int) (56B)

struct ReconBuffer;

struct SimpleReconObject {
    char pad[4];
    void* m_inner;
    void DoStream(ReconBuffer* buf, int arg);
};

void SimpleReconObject::DoStream(ReconBuffer* buf, int arg) {
    void* inner = m_inner;
    int* vt = *(int**)inner;
    short adj = *(short*)((char*)vt + 176);
    void (*fn)(void*, ReconBuffer*, int) = (void (*)(void*, ReconBuffer*, int))*(void**)((char*)vt + 180);
    fn((char*)inner + adj, buf, arg);
}
