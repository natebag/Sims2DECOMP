// VERSION_DIFF: compiled 100B vs DOL 108B — loop uses 4 callee-saved regs vs 5, direct field access vs address-of pattern
/* ERModel::DrawGeometry(ERC *) at 0x80318950 (108B) */

extern void SubDraw(void *, void *);

struct ERModelDG {
    char pad[0x3C];
    char *m_subModels;
    int m_numSubModels;
    void DrawGeometry(void *erc);
};

void ERModelDG::DrawGeometry(void *erc) {
    int offset = 0;
    for (int i = 0; i < m_numSubModels; i++) {
        SubDraw(m_subModels + offset, erc);
        offset += 24;
    }
}
