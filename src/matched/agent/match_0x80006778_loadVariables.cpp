/* loadVariables(char *) at 0x80006778 (40B) */

extern char g_loadVarsTarget[];

void loadVariablesImpl(void*);

void loadVariables(char* url) {
    loadVariablesImpl(g_loadVarsTarget);
}
