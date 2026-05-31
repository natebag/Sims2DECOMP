// 0x800067A0 (40 bytes) loadVariablesNULL(void)
// Passes the address of a static string to AptValueFactory::CreateString.
// Referencing the string by symbol (not an integer-literal cast) makes the
// compiler emit the lis@ha / addi@l relocation pair instead of lis / ori.
struct AptValueFactory {
    static void CreateString(char*);
};

extern char s_loadVarsNullName[16];

void loadVariablesNULL() {
    AptValueFactory::CreateString(s_loadVarsNullName);
}
