// FLAGS: -msdata=eabi -G 8
// 0x8033795C VideoDecodeThreadStart (52b)
extern int g_videoDecThread;
extern void LogFunc(const char*);
extern char g_videoDecName[];

void VideoDecodeThreadStart(void* arg) {
    if (g_videoDecThread != 0) {
        LogFunc(g_videoDecName);
    }
}
