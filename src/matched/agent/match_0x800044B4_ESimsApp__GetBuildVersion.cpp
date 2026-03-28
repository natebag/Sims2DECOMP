/* ESimsApp::GetBuildVersion(void) at 0x800044B4 (12B) */

extern char g_buildVersion[];

struct ESimsApp {
    char* GetBuildVersion(void);
};

char* ESimsApp::GetBuildVersion(void) {
    return g_buildVersion;
}
