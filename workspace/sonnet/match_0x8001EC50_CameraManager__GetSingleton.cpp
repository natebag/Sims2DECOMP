// 0x8001EC50 CameraManager::GetSingleton (68b)

extern int gCameraManager;

void* SimsAlloc(int size);
void* CameraManagerInit(void* mem);
void CameraManagerPostInit(void* mgr);

void* CameraManager_GetSingleton() {
    if (gCameraManager == 0) {
        void* mem = SimsAlloc(8);
        int mgr = (int)CameraManagerInit(mem);
        gCameraManager = mgr;
        CameraManagerPostInit((void*)mgr);
    }
    return (void*)gCameraManager;
}
