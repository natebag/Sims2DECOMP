int strcmp(const char* a, const char* b);

extern char g_tattooVarName[];

class CASTattooTarget {
public:
    void SetVariable(char* name, char* value);
};

void CASTattooTarget::SetVariable(char* name, char* value) {
    strcmp(g_tattooVarName, name);
}
