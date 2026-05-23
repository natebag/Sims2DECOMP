extern "C" int getEyeToyDevice(void);
int EyeToyClient_IsEyeToyHardwarePresent() {
    int dev = getEyeToyDevice();
    if (dev != -1) return 1;
    return 0;
}
