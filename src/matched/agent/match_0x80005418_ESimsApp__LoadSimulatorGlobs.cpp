/* ESimsApp::LoadSimulatorGlobs(void) at 0x80005418 (32B) */

void LoadAllGlobs(void);

struct ESimsApp {
    void LoadSimulatorGlobs(void);
};

void ESimsApp::LoadSimulatorGlobs(void) {
    LoadAllGlobs();
}
