/* ESimsApp::SetupForMovie(void) at 0x80005CAC (40B) */

extern char g_simsApp[];

void SetupForMovieImpl(void*);

struct ESimsApp {
    void SetupForMovie(void);
};

void ESimsApp::SetupForMovie(void) {
    SetupForMovieImpl(g_simsApp);
}
