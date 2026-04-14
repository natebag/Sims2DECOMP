// 0x80005CAC ESimsApp::SetupForMovie (40B)

extern char gInteractorModule[];
void EGlobal_SetupScratchHeap(void* module);

struct ESimsApp {
    void SetupForMovie();
};

void ESimsApp::SetupForMovie() {
    EGlobal_SetupScratchHeap(gInteractorModule);
}
