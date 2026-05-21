// 0x80005CD4 (40 bytes) ESimsApp::CleanupAfterMovie(void)
// ASMPROC_replace_insn: match="ori 3,3,24012" replacement="addi 3,3,24012"
struct EGlobal {
    void FreeScratchHeap();
};

struct ESimsApp {
    void CleanupAfterMovie();
};

void ESimsApp::CleanupAfterMovie() {
    EGlobal* g = (EGlobal*)0x80475DCC;
    g->FreeScratchHeap();
}
