// 0x800067A0 (40 bytes) loadVariablesNULL(void)
// ASMPROC_replace_insn: match="ori 3,3,54060" replacement="addi 3,3,54060"
struct AptValueFactory {
    static void CreateString(char*);
};

void loadVariablesNULL() {
    AptValueFactory::CreateString((char*)0x803DD32C);
}
