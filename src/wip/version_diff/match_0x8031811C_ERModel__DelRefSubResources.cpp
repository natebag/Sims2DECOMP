// VERSION_DIFF: loop pattern — compiler generates direct field access vs DOL address-of pattern
/* ERModel::DelRefSubResources(void) at 0x8031811C (100B) */

extern void SubDelRef(void *);

struct ERModelDR {
    char pad[0x3C];
    char *m_subModels;
    int m_numSubModels;
    void DelRefSubResources(void);
};

void ERModelDR::DelRefSubResources(void) {
    int offset = 0;
    for (int i = 0; i < m_numSubModels; i++) {
        SubDelRef(m_subModels + offset);
        offset += 24;
    }
}
