/* GetBuidVersionLine(void) at 0x8023CA50 (72B) */
// FLAGS: -fno-elide-constructors

extern char g_verBuf[256];
extern char g_verFmt[64];
extern char g_verParam[64];
extern int ver_sprintf(char *, char *, ...);

char *GetBuidVersionLine(void) {
    ver_sprintf(g_verBuf, g_verFmt, g_verParam);
    return g_verBuf;
}
