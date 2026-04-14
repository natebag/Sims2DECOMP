/* ESimsApp::GetAppName(void) at 0x80006380 (12B) */

extern char g_appName[];

struct ESimsApp {
    char* GetAppName(void);
};

char* ESimsApp::GetAppName(void) {
    return g_appName;
}
