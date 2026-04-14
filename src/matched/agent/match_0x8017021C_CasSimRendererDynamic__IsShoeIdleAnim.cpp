// 0x8017021C CasSimRendererDynamic::IsShoeIdleAnim(unsigned int) (36B)
struct AnimTable {
    int pad_0_59[15];
    int m_shoe1;   // 60
    int pad_64_99[9];
    int m_shoe2;   // 100
};

struct CasSimRendererDynamic {
    char pad[548];
    AnimTable* m_table;
};

int CasSimRendererDynamic__IsShoeIdleAnim(CasSimRendererDynamic* self, unsigned int id) {
    AnimTable* t = self->m_table;
    int r = 0;
    if (id == (unsigned int)t->m_shoe1 || id == (unsigned int)t->m_shoe2) r = 1;
    return r;
}
