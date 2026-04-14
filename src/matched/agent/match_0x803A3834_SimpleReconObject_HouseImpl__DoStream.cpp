// 0x803A3834 SimpleReconObject<HouseImpl>::DoStream(ReconBuffer*, int) (56B)

struct ReconBuffer;

struct SimpleReconObject {
    char pad[4];
    void* m_inner;
    void DoStream(ReconBuffer* buf, int arg);
};

void SimpleReconObject::DoStream(ReconBuffer* buf, int arg) {
    void* inner = m_inner;
    int* vt = *(int**)inner;
    short adj = *(short*)((char*)vt + 96);
    void (*fn)(void*, ReconBuffer*, int) = (void (*)(void*, ReconBuffer*, int))*(void**)((char*)vt + 100);
    fn((char*)inner + adj, buf, arg);
}
