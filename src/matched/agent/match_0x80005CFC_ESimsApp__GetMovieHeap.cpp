// 0x80005CFC (48 bytes) ESimsApp::GetMovieHeap(void)
struct EGlobal;
extern void* TextureHeap();

struct ESimsApp {
    void* GetMovieHeap();
};

struct MovieHeapGlobals {
    char pad[0x5F1C];
    void* movieHeap;
};

void* ESimsApp::GetMovieHeap() {
    MovieHeapGlobals* g = (MovieHeapGlobals*)0x80470000;
    if (g->movieHeap == 0) {
        return TextureHeap();
    }
    return g->movieHeap;
}
