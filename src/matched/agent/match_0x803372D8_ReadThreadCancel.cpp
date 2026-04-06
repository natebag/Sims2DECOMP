// FLAGS: -msdata=eabi -G 8
// 0x803372D8 ReadThreadCancel (60b)
extern int g_readThread;
extern void CancelThread(const char*);
extern char g_readThreadName[];

void ReadThreadCancel() {
    if (g_readThread != 0) {
        CancelThread(g_readThreadName);
        g_readThread = 0;
    }
}
