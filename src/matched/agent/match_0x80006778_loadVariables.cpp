// 0x80006778 (40 bytes) loadVariables(char*)
// ASMPROC_replace_insn: match="ori 3,3,54012" replacement="addi 3,3,54012"
struct AptValueFactory {
    static void CreateString(char*);
};

void loadVariables() {
    AptValueFactory::CreateString((char*)0x803DD2FC);
}
