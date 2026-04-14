// 0x80038FE0 EyeToyClient::IsSessionEyeToyDisconnected (52B)

extern char gEyeToyDev[4];
extern "C" int isDisconnected(int);

int EyeToyClient_IsSessionEyeToyDisconnected() {
    int dev = *(int*)gEyeToyDev;
    if (dev == -1) {
        return 1;
    }
    return isDisconnected(dev);
}
