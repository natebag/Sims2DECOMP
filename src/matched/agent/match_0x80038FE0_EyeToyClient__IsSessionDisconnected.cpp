extern char gEyeToyDev[4];
extern "C" int isDisconnected(int);
int EyeToyClient_IsSessionEyeToyDisconnected() {
    int dev = *(int*)gEyeToyDev;
    int arg = 1;
    if (dev != -1) {
        arg = dev;
    }
    return isDisconnected(arg);
}
