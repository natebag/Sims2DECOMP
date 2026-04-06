// FLAGS: -msdata=eabi -G 8
// 0x80337608 AudioDecodeThreadCancel (60b)
extern int g_audioDecThread;
extern void CancelThread(const char*);
extern char g_audioDecName[];

void AudioDecodeThreadCancel() {
    if (g_audioDecThread != 0) {
        CancelThread(g_audioDecName);
        g_audioDecThread = 0;
    }
}
