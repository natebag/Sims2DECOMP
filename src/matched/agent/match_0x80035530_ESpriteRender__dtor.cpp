// 0x80035530 (88B) ESpriteRender::~ESpriteRender(void)
// Variant L: SI deleting-dtor with MainHeap delete branch — vtable@+0xe8 + DeleteShaders + clear m_8 + MainHeap()->Free.

extern char vt_ESpriteRender[];

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

void ESpriteRender_DeleteShaders(void* obj);

struct ESpriteRender {
    char pad_0_7[8];
    int m_field_8;
    char pad_c_e7[220];
    void* m_vt_at_e8;
    void dtor(int flag);
};

void ESpriteRender::dtor(int flag) {
    m_vt_at_e8 = vt_ESpriteRender;
    ESpriteRender_DeleteShaders(this);
    m_field_8 = 0;
    if (flag & 1) {
        MainHeap()->Free(this);
    }
}
