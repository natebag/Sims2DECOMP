// 0x8001606C CameraMotionSystem::CameraMotionSystem (20b)

struct CameraMotionSystem {
    int f0;
    int f4;
    CameraMotionSystem(int p2);
};

CameraMotionSystem::CameraMotionSystem(int p2) {
    CameraMotionSystem* p = this;
    p->f0 = 0;
    p->f4 = p2;
}
