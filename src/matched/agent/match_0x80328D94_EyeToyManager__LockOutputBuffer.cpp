// 0x80328D94 (40b)
// EyeToyManager::LockOutputBuffer(int)

extern void EyeToyManager_LockBufferImpl(int);

void EyeToyManager_LockOutputBuffer(int handle) {
    if (handle != -1) {
        EyeToyManager_LockBufferImpl(handle);
    }
}
