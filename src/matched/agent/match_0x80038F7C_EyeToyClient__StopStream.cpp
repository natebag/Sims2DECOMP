/* EyeToyClient::EyeToyClient__StopStream(void) at 0x80038F7C (52B) */

extern int g_ets_0x80038F7C;
extern int etf_0x80038F7C(int);

int EyeToyClient_EyeToyClient__StopStream(void) {
    int handle = g_ets_0x80038F7C;
    if (handle == -1) return 0;
    return etf_0x80038F7C(handle);
}
