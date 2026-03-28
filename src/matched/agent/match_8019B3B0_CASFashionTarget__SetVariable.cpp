int strcmp(const char* a, const char* b);

extern char g_fashionVarName[];

class CASFashionTarget {
public:
    void RandomizeFashion(void);
    void SetVariable(char* name, char* value);
};

void CASFashionTarget::SetVariable(char* name, char* value) {
    if (strcmp(g_fashionVarName, name) == 0) {
        RandomizeFashion();
    }
}
