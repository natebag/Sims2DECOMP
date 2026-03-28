extern int gAptEnabled;

struct ESimsAppData {
    char pad[0xB4];
    void* m_aptViewer;
};

extern ESimsAppData gAppData;

void AptViewerUpdate(void* viewer, int a, int b, int c, int d);
void AptViewerRender(void* viewer);

void ESimsApp_UpdateApt() {
    if (gAptEnabled != 0) {
        AptViewerUpdate(gAppData.m_aptViewer, 0, 0, 0, 1);
        AptViewerRender(gAppData.m_aptViewer);
    }
}
