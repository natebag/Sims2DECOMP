// 0x800384E8 EyeToyClient::UnpluggedCallback(int) (48B)

extern void (*g_eyeToyUnpluggedCallback)(int);

void EyeToyClient_UnpluggedCallback(int param) {
    void (*fn)(int) = g_eyeToyUnpluggedCallback;
    if (fn)
        fn(param);
}
