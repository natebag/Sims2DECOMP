// 0x803A8220 SimpleReconObject<ObjectFolderImpl>::DoStream(ReconBuffer*, int) (56B)

struct ReconBuffer;

struct SimpleReconObject {
    char pad[4];
    void* m_inner;
    void DoStream(ReconBuffer* buf, int arg);
};

void SimpleReconObject::DoStream(ReconBuffer* buf, int arg) {
    void* inner = m_inner;
    int* vt = *(int**)inner;
    short adj = *(short*)((char*)vt + 312);
    void (*fn)(void*, ReconBuffer*, int) = (void (*)(void*, ReconBuffer*, int))*(void**)((char*)vt + 316);
    fn((char*)inner + adj, buf, arg);
}
