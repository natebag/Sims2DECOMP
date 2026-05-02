// 0x80327F58 (80B) EScratchBuffMan::~EScratchBuffMan(void)
// Variant L: SI deleting-dtor — MainHeap()->Free(m_buf) + clear m_buf + delete branch.

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

void __builtin_delete(void* p);

struct EScratchBuffMan {
    char pad_00_0b[12];
    void* m_field_0c;
    void dtor(int flag);
};

void EScratchBuffMan::dtor(int flag) {
    MainHeap()->Free(m_field_0c);
    m_field_0c = 0;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
