// 0x8017D254 UIReflow::~UIReflow(void) (92B)
// Pattern: dtor — free buffer via MainHeap if allocated; compiler emits delete branch from in_free arg
class EAHeap {
public:
    void Free(void* p);
};
extern EAHeap* MainHeap();

struct UIReflow {
    void* m_buf;
    ~UIReflow();
};

UIReflow::~UIReflow() {
    if (m_buf != 0) {
        EAHeap* h = MainHeap();
        h->Free(m_buf);
        m_buf = 0;
    }
}
