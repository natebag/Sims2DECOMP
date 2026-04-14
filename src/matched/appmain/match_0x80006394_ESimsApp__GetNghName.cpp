/* ESimsApp::GetNghName(void) at 0x80006394 (12B) */

extern char g_nghName[];

struct ESimsApp {
    char* GetNghName(void);
};

char* ESimsApp::GetNghName(void) {
    return g_nghName;
}
