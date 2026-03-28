extern char gAppData3[];

void CleanupAfterMovieImpl(char* app);

void ESimsApp_CleanupAfterMovie() {
    CleanupAfterMovieImpl(gAppData3);
}
