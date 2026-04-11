// VERSION_DIFF: loop offset init placed before guard check vs after
/* ESubModel::FreeMorphResource(void) at 0x802FB6DC (92B) */

extern void FreeRes(void *);

struct ESubModelFMR {
    char *m_resources;
    int m_numResources;
    void FreeMorphResource(void);
};

void ESubModelFMR::FreeMorphResource(void) {
    int offset = 0;
    for (int i = 0; i < m_numResources; i++) {
        FreeRes(m_resources + offset);
        offset += 0x70;
    }
}
