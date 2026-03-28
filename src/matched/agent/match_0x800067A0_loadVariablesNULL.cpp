extern char gNullVarFilePath[];

void LoadVarsImpl(char* path);

void loadVariablesNULL() {
    LoadVarsImpl(gNullVarFilePath);
}
