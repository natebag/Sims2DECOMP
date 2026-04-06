// FLAGS: -msdata=eabi -G 8
// 0x80337990 VideoDecodeThreadCancel (60b)
extern int g_videoDecThread;
extern void CancelThread(const char*);
extern char g_videoDecName[];

void VideoDecodeThreadCancel() {
    if (g_videoDecThread != 0) {
        CancelThread(g_videoDecName);
        g_videoDecThread = 0;
    }
}
