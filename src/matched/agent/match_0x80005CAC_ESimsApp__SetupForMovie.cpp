extern char gAppData2[];

void SetupForMovieImpl(char* app);

void ESimsApp_SetupForMovie() {
    SetupForMovieImpl(gAppData2);
}
