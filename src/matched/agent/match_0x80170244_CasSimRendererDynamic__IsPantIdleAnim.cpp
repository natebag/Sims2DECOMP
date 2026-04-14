// 0x80170244 CasSimRendererDynamic::IsPantIdleAnim(unsigned int) (52B)
// 3-way OR pattern: id matches any of 3 fields → return 1
struct AnimTable {
    int pad_0_27[7];
    int m_pant1;   // 28
    int pad_32_87[14];
    int m_pant2;   // 88
    int m_pant3;   // 92
};

struct CasSimRendererDynamic {
    char pad[548];
    AnimTable* m_table;
};

int CasSimRendererDynamic__IsPantIdleAnim(CasSimRendererDynamic* self, unsigned int id) {
    AnimTable* t = self->m_table;
    int r = 0;
    if (id == (unsigned int)t->m_pant1 || id == (unsigned int)t->m_pant2 || id == (unsigned int)t->m_pant3) r = 1;
    return r;
}
