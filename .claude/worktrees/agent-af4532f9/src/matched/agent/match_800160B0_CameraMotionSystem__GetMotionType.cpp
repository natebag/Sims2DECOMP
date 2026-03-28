// 0x800160B0 (8 bytes) — lwz r3, 0x0(r3); blr

class CameraMotionSystem {
public:
    int m_motionType;  // 0x000

    int GetMotionType();
};

int CameraMotionSystem::GetMotionType() {
    return m_motionType;
}
