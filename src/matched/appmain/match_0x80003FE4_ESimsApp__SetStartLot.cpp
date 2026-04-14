/* ESimsApp::SetStartLot(int) at 0x80003FE4 (8B) */

extern int g_startLot;

struct ESimsApp {
    void SetStartLot(int);
};

void ESimsApp::SetStartLot(int lot) {
    g_startLot = lot;
}
