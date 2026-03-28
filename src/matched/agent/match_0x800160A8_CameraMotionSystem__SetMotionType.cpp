/* CameraMotionSystem::SetMotionType(CameraMotionType) at 0x800160A8 (8B) */

struct CameraMotionSystem {
    int m_motionType;

    void SetMotionType(int type);
};

void CameraMotionSystem::SetMotionType(int type) {
    m_motionType = type;
}
