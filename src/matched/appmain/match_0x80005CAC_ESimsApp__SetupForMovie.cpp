// 0x80005CAC (40 bytes) ESimsApp::SetupForMovie(void)
// ASMPROC_replace_insn: match="ori 3,3,24012" replacement="addi 3,3,24012"
struct EGlobal {
    void SetupScratchHeap();
};

struct ESimsApp {
    void SetupForMovie();
};

void ESimsApp::SetupForMovie() {
    EGlobal* g = (EGlobal*)0x80475DCC;
    g->SetupScratchHeap();
}
