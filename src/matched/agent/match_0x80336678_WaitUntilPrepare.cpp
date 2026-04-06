// FLAGS: -msdata=eabi -G 8
// 0x80336678 WaitUntilPrepare (68b)
extern int OSReceiveMessage(char* queue, int* msg, int flags);
extern char g_prepareQueue[];

int WaitUntilPrepare() {
    int msg;
    OSReceiveMessage(g_prepareQueue, &msg, 1);
    if (msg != 0) {
        return 1;
    }
    return 0;
}
