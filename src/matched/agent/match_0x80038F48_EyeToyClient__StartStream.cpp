/* EyeToyClient::StartStream(void) at 0x80038F48 (52B) */

extern int g_eyetoySession;
extern int eyetoyStreamStart(int);

int EyeToyClient_StartStream(void) {
    int handle = g_eyetoySession;
    if (handle == -1) return 0;
    return eyetoyStreamStart(handle);
}
