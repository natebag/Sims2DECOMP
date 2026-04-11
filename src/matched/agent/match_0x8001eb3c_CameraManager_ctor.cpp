// 0x8001EB3C CameraManager::CameraManager (20b)

struct CameraManager {
    int f0;
    int f4;
    CameraManager();
};

CameraManager::CameraManager() {
    CameraManager* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
