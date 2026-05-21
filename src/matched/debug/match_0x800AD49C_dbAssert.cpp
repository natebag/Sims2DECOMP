// 0x800AD49C dbAssert(char*, unsigned int, char*) (68B)

extern char* g_assertMsg;          // SDA -24520
extern char* g_assertFile;         // SDA -24516
extern unsigned int g_assertLine;  // SDA -24524
extern int g_assertOldInfo;        // SDA -24512
extern int g_assertActive;         // SDA -32120 (far)

extern int WaitForControllerButton(int);

void dbAssert(char* msg, unsigned int line, char* file) {
    int old = g_assertOldInfo;
    g_assertMsg = msg;
    g_assertActive = 1;
    g_assertLine = line;
    g_assertFile = file;
    g_assertOldInfo = 0;
    WaitForControllerButton(old);
}
