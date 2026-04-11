/* EyeToyClient::FrameReadyCallback(char *, int) at 0x80037930 (64B) */

extern int g_eyetoyFramePtr;
extern int g_eyetoyInstance;

void EyeToyManager_LockOutputBuffer(int instance);

void EyeToyClient_FrameReadyCallback(char *buf, int size) {
    if (g_eyetoyFramePtr == 0) {
        EyeToyManager_LockOutputBuffer(g_eyetoyInstance);
    }
    g_eyetoyFramePtr = (int)buf;
}
