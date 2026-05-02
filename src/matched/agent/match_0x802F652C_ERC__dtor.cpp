// 0x802F652C (84B) ERC::~ERC(void)
// Variant L: vtable@+0x70 (after EString member at +0x6c) + EString::Deallocate(m_data) + __builtin_delete branch.

extern char vt_ERC[];

class EString {
public:
    char* m_data;
    void Deallocate(char* data);
};

void __builtin_delete(void* p);

struct ERC {
    char pad_00_6b[108];
    EString m_estring;
    void* m_vt_at_70;
    void dtor(int flag);
};

void ERC::dtor(int flag) {
    m_vt_at_70 = vt_ERC;
    m_estring.Deallocate(m_estring.m_data);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
