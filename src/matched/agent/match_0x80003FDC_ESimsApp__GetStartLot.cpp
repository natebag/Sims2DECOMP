/* ESimsApp::GetStartLot(void) at 0x80003FDC (8B) */

extern int g_startLot;

struct ESimsApp {
    int GetStartLot(void);
};

int ESimsApp::GetStartLot(void) {
    return g_startLot;
}
