// FLAGS: -fno-elide-constructors
// 0x800160B8 CameraMotionSystem_SetRig (88B)
struct EVec3 {
    float x, y, z;
};

struct CameraMotionSystem {
    char pad[0x08];
    EVec3 pos;
    EVec3 target;
    EVec3 up;

    void SetRig(EVec3& p, EVec3& t, EVec3& u);
};

void CameraMotionSystem::SetRig(EVec3& p, EVec3& t, EVec3& u) {
    pos = p;
    target = t;
    up = u;
}
