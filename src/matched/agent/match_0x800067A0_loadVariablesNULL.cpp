/* loadVariablesNULL(void) at 0x800067A0 (40B) */

extern char g_loadVarsNullTarget[];

void loadVariablesNullImpl(void*);

void loadVariablesNULL(void) {
    loadVariablesNullImpl(g_loadVarsNullTarget);
}
