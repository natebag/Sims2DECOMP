// 0x80006778 (40 bytes) loadVariables(char*)
// Passes the address of a static string to AptValueFactory::CreateString.
// Referencing the string by symbol (not an integer-literal cast) makes the
// compiler emit the lis@ha / addi@l relocation pair instead of lis / ori.
struct AptValueFactory {
    static void CreateString(char*);
};

extern char s_loadVarsName[16];

void loadVariables() {
    AptValueFactory::CreateString(s_loadVarsName);
}
