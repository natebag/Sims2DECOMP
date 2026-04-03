// 0x800160B0 (8 bytes)
class CameraMotionSystem {
public:
    int GetMotionType();
};

int CameraMotionSystem::GetMotionType() {
    return *(int*)((char*)this + 0x0);
}
