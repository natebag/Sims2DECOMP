// 0x80003FDC ESimsApp::GetStartLot (8b)

extern int g_startLot;

struct ESimsApp {
    int GetStartLot(void);
};

int ESimsApp::GetStartLot(void) {
    return g_startLot;
}
