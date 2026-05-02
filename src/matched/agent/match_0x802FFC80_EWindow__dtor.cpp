// 0x802FFC80 (112B) EWindow::~EWindow(void)
// Variant K: vtable@+0x9c + dual SDA-singleton clear (if matching this) + MainHeap delete branch.

extern char vt_EWindow[];
extern void* g_window_a;
extern void* g_window_b;

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

struct EWindow {
    char pad_0_9b[156];
    void* m_vt_at_9c;
    void dtor(int flag);
};

void EWindow::dtor(int flag) {
    m_vt_at_9c = vt_EWindow;
    if (g_window_a == this) g_window_a = 0;
    if (g_window_b == this) g_window_b = 0;
    if (flag & 1) {
        MainHeap()->Free(this);
    }
}
