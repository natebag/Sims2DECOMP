// 0x80170278 CasSimRendererDynamic::IsRegularIdleAnim(unsigned int) (52B)
// 3-way OR pattern: id matches any of 3 fields → return 1
struct AnimTable {
    int m_regular1;   // 0
    int m_regular2;   // 4
    int m_regular3;   // 8
};

struct CasSimRendererDynamic {
    char pad[548];
    AnimTable* m_table;
};

int CasSimRendererDynamic__IsRegularIdleAnim(CasSimRendererDynamic* self, unsigned int id) {
    AnimTable* t = self->m_table;
    int r = 0;
    if (id == (unsigned int)t->m_regular1 || id == (unsigned int)t->m_regular2 || id == (unsigned int)t->m_regular3) r = 1;
    return r;
}
