// 0x80087458 (124B) TextItem::~TextItem(void)
// Variant L (TextBaseItem sibling): MI vtable transition + conditional MainHeap free + 2 helpers + delete branch.

extern char vt_TextItem_a[];
extern char vt_TextItem_b[];

class EAHeap {
public:
    void Free(void* p);
};
EAHeap* MainHeap();

void TextItem_helper1(void* obj);
void TextItem_helper2(void* obj);
void __builtin_delete(void* p);

struct TextItem {
    char pad_0_1b[28];
    void* m_vt_at_1c;
    char pad_20_43[36];
    void* m_field_44;
    void dtor(int flag);
};

void TextItem::dtor(int flag) {
    void* p = m_field_44;
    m_vt_at_1c = vt_TextItem_a;
    if (p != 0) {
        MainHeap()->Free(p);
    }
    m_vt_at_1c = vt_TextItem_b;
    TextItem_helper1(this);
    TextItem_helper2(this);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
