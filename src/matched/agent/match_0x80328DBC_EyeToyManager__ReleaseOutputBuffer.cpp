// 0x80328DBC (40b)
// EyeToyManager::ReleaseOutputBuffer(int)

extern void EyeToyManager_ReleaseBufferImpl(int);

void EyeToyManager_ReleaseOutputBuffer(int handle) {
    if (handle != -1) {
        EyeToyManager_ReleaseBufferImpl(handle);
    }
}
