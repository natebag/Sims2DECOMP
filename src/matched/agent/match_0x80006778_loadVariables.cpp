extern char gVarFilePath[];

void LoadVarsImpl(char* path);

void loadVariables(char* name) {
    LoadVarsImpl(gVarFilePath);
}
