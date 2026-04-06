// 0x80328EE4 EyeToyManager::SetAttributes (40b)

extern void EyeToyManager_SetAttributesImpl(int, int, void*);

void EyeToyManager_SetAttributes(int handle, int flags, void* attrs) {
    if (handle != -1) {
        EyeToyManager_SetAttributesImpl(handle, flags, attrs);
    }
}
