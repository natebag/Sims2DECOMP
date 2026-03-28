// 0x800160A8 (8 bytes)
class CameraMotionSystem {
public:
    void SetMotionType(int p);
};

void CameraMotionSystem::SetMotionType(int p) {
    *(int*)((char*)this + 0x0) = p;
}
