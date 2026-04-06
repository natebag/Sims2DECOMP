// 0x80328E54 EyeToyManager::ResetStream (40b)

extern void EyeToyManager_ResetStreamImpl(int, int);

void EyeToyManager_ResetStream(int handle, int resolution) {
    if (handle != -1) {
        EyeToyManager_ResetStreamImpl(handle, resolution);
    }
}
