// 0x80364098 (108B) EFontData::~EFontData(void)
// Variant L (MI vtable transition): vt_a@+0 + Deallocate + member dtor at +0x28 (flag=2) + member dtor at +0x4 + vt_b@+0 + delete branch.

extern char vt_EFontData_a[];
extern char vt_EFontData_b[];

void EFontData_Deallocate(void* obj);
void EFontData_member_a_dtor(void* obj, int flag);
void EFontData_member_b_dtor(void* obj);
void __builtin_delete(void* p);

struct MemberA { char data[1]; };
struct MemberB { char data[1]; };

struct EFontData {
    void* m_vt_at_0;
    MemberB m_member_b;
    char pad_5_27[35];
    MemberA m_member_a;
    void dtor(int flag);
};

void EFontData::dtor(int flag) {
    m_vt_at_0 = vt_EFontData_a;
    EFontData_Deallocate(this);
    EFontData_member_a_dtor(&m_member_a, 2);
    EFontData_member_b_dtor(&m_member_b);
    m_vt_at_0 = vt_EFontData_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
