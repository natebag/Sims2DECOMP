// FLAGS: -msdata=eabi -G 8
// 0x803372A4 ReadThreadStart (52b)
extern int g_readThread;
extern void LogFunc(const char*);
extern char g_readThreadName[];

void ReadThreadStart(void* arg) {
    if (g_readThread != 0) {
        LogFunc(g_readThreadName);
    }
}
