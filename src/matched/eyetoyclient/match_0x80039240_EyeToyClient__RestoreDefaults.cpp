extern void* gEyeToyDevice;
extern "C" void resetDevice(void*, int);
void EyeToyClient_RestoreDefaults() {
    if (gEyeToyDevice != (void*)-1) {
        resetDevice(gEyeToyDevice, -1);
    }
}
