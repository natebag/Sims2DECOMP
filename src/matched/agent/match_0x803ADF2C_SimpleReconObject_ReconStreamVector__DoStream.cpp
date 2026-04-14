// 0x803ADF2C SimpleReconObject<ReconStreamVector<SlotDescriptor>>::DoStream(ReconBuffer*, int) (52B)

struct ReconBuffer;
struct SlotDescriptor;

struct SimpleReconObject {
    char pad[4];
    void* m_inner;
    void DoStream(ReconBuffer* buf, int arg);
};

extern "C" void RSV_DoStream(void* inner, void* vt0, ReconBuffer* buf, int arg);  // 0x803ade14

void SimpleReconObject::DoStream(ReconBuffer* buf, int arg) {
    void* inner = m_inner;
    int* vt = *(int**)inner;
    RSV_DoStream(vt, (void*)(long)*vt, buf, arg);
}
