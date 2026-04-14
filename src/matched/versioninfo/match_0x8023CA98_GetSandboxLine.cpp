/* GetSandboxLine(void) at 0x8023CA98 (72B) */
// FLAGS: -fno-elide-constructors

extern char g_sbBuf[256];
extern char g_sbFmt[64];
extern char g_sbParam[64];
extern int sb_sprintf(char *, char *, ...);

char *GetSandboxLine(void) {
    sb_sprintf(g_sbBuf, g_sbFmt, g_sbParam);
    return g_sbBuf;
}
