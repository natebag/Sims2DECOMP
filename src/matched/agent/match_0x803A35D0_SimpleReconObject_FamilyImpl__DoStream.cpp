// 0x803A35D0 SimpleReconObject<FamilyImpl>::DoStream(ReconBuffer*, int) (56B)

struct ReconBuffer;

struct SimpleReconObject {
    char pad[4];
    void* m_inner;
    void DoStream(ReconBuffer* buf, int arg);
};

void SimpleReconObject::DoStream(ReconBuffer* buf, int arg) {
    void* inner = m_inner;
    int* vt = *(int**)inner;
    short adj = *(short*)((char*)vt + 120);
    void (*fn)(void*, ReconBuffer*, int) = (void (*)(void*, ReconBuffer*, int))*(void**)((char*)vt + 124);
    fn((char*)inner + adj, buf, arg);
}
