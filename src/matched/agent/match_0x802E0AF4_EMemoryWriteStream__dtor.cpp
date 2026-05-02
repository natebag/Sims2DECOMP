// 0x802E0AF4 (108B) EMemoryWriteStream::~EMemoryWriteStream(void)
// Variant L (MI): vtable-transition at +0x18 + 2 helper calls on m_field_20 + delete branch.

extern char vt_EMemoryWriteStream_a[];
extern char vt_EMemoryWriteStream_b[];

void Stream_helper_a(void* obj);
void Stream_helper_b(void* obj, int flag);
void __builtin_delete(void* p);

struct ChildObj {
    char data[1];
};

struct EMemoryWriteStream {
    char pad_00_17[24];
    void* m_vt_at_18;
    char pad_1c_1f[4];
    ChildObj m_field_20;
    void dtor(int flag);
};

void EMemoryWriteStream::dtor(int flag) {
    m_vt_at_18 = vt_EMemoryWriteStream_a;
    Stream_helper_a(&m_field_20);
    Stream_helper_b(&m_field_20, 2);
    m_vt_at_18 = vt_EMemoryWriteStream_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
