// 0x8017E920 UIReflow::OpenReflowBlock(void) (120B)
// Pattern: lazy-alloc reflow buffer via MainHeap + initial block write
class EAHeap {
public:
    void* Malloc(unsigned int size, int pad);
};
extern EAHeap* MainHeap();
extern char gStr_OpenBlock[];

struct UIReflow {
    char* m_buf;
    char* m_cur;
    int m_flag;
    int m_capacity;
    int m_16;
    void AddToBlock(char*);
    void OpenReflowBlock();
};

void UIReflow::OpenReflowBlock() {
    char* old = m_buf;
    if (old != 0) return;
    m_flag = 1;
    m_capacity = 4096;
    EAHeap* h = MainHeap();
    char* p = (char*)h->Malloc(m_capacity, 0);
    m_16 = (int)old;
    m_buf = p;
    m_cur = p;
    if (p != 0) {
        AddToBlock(gStr_OpenBlock);
    }
}
