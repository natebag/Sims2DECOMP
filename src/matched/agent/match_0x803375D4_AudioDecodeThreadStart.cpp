// FLAGS: -msdata=eabi -G 8
// 0x803375D4 AudioDecodeThreadStart (52b)
extern int g_audioDecThread;
extern void LogFunc(const char*);
extern char g_audioDecName[];

void AudioDecodeThreadStart(void* arg) {
    if (g_audioDecThread != 0) {
        LogFunc(g_audioDecName);
    }
}
