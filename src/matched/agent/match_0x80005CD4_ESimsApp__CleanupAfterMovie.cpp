/* ESimsApp::CleanupAfterMovie(void) at 0x80005CD4 (40B) */

extern char g_simsApp2[];

void CleanupAfterMovieImpl(void*);

struct ESimsApp {
    void CleanupAfterMovie(void);
};

void ESimsApp::CleanupAfterMovie(void) {
    CleanupAfterMovieImpl(g_simsApp2);
}
