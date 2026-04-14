/* EyeToyClient::SetUnplugCallback(void (*)(int)) - 0x800384E0 (8 bytes) */

typedef void (*UnplugCallback)(int);
extern UnplugCallback g_unplugCallback;

struct EyeToyClient {
    static void SetUnplugCallback(UnplugCallback cb);
};

void EyeToyClient::SetUnplugCallback(UnplugCallback cb) {
    g_unplugCallback = cb;
}
