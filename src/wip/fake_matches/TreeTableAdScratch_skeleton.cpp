// 0x801499BC TreeTableAdScratch::TreeTableAdScratch (44b)
// Pattern: Vtable + mixed fields (shorts + words)

extern int TreeTableAdScratch_vtable[];

struct TreeTableAdScratch {
    int* m_vt;      // offset 0
    short m_s4;     // offset 4
    short m_s6;     // offset 6
    short m_s8;     // offset 8
    char _pad[2];   // offset 10
    int m_i12;      // offset 12
    TreeTableAdScratch();
};

TreeTableAdScratch::TreeTableAdScratch() {
    TreeTableAdScratch* p = this;
    p->m_vt = (int*)TreeTableAdScratch_vtable;
    p->m_s8 = 0;
    p->m_i12 = 0;
    p->m_s4 = 0;
    p->m_s6 = 0;
}
