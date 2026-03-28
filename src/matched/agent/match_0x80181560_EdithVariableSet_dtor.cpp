
extern char g_edithVarSetGlobal[];

void EdithVarSetRelease(char *, int);

struct EdithVariableSet {
    int m_vars[13];
    char _pad_034[0x74];
    int m_field_0A8;

    void Release(void);
};

void EdithVariableSet::Release(void) {
    int* p = m_vars;
    int* end = m_vars + 13;
    do {
        EdithVarSetRelease(g_edithVarSetGlobal, *p);
        p++;
    } while ((int)p <= (int)end);
    m_field_0A8 = 1;
}
