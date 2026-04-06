/* PopReadedBuffer(void) at 0x803373F4 (52B) */

extern char g_rdBufQ[64];
extern int OSRecvMsg(void *, int *, int);

int PopReadedBuffer(void) {
    int msg;
    OSRecvMsg(g_rdBufQ, &msg, 1);
    return msg;
}
