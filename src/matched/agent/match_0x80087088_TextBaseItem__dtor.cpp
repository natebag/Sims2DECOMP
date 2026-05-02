// 0x80087088 (124B) TextBaseItem::~TextBaseItem(void)
// Variant L (MI vtable transition): vt_a@+0x1c → conditional MainHeap free m_44 → vt_b@+0x1c → 2 helpers → delete branch.

extern char vt_TextBaseItem_a[];
extern char vt_TextBaseItem_b[];

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

void TextBaseItem_helper1(void* obj);
void TextBaseItem_helper2(void* obj);
void __builtin_delete(void* p);

struct TextBaseItem {
    char pad_0_1b[28];
    void* m_vt_at_1c;
    char pad_20_43[36];
    void* m_field_44;
    void dtor(int flag);
};

void TextBaseItem::dtor(int flag) {
    void* p = m_field_44;
    m_vt_at_1c = vt_TextBaseItem_a;
    if (p != 0) {
        MainHeap()->Free(p);
    }
    m_vt_at_1c = vt_TextBaseItem_b;
    TextBaseItem_helper1(this);
    TextBaseItem_helper2(this);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
