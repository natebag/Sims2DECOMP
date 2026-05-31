// 0x80005CD4 (40 bytes) ESimsApp::CleanupAfterMovie(void)
// Calls FreeScratchHeap() on the EGlobal singleton. Referencing the singleton
// by symbol (not an integer-literal cast) makes the compiler emit the
// lis@ha / addi@l relocation pair instead of lis / ori. EGlobal is a large
// singleton object, so it is never placed in small-data (no SDA r13 form).
struct EGlobal {
    char _reserved[64];
    void FreeScratchHeap();
};

struct ESimsApp {
    void CleanupAfterMovie();
};

extern EGlobal gEGlobal;

void ESimsApp::CleanupAfterMovie() {
    gEGlobal.FreeScratchHeap();
}
