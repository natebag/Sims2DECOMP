// 0x800160A8 (8 bytes) — stw r4, 0x0(r3); blr

class CameraMotionSystem {
public:
    int m_motionType;  // 0x000

    void SetMotionType(int type);
};

void CameraMotionSystem::SetMotionType(int type) {
    m_motionType = type;
}
