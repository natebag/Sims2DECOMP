/* CameraMotionSystem::GetMotionType(void) at 0x800160B0 (8B) */

struct CameraMotionSystem {
    int m_motionType;

    int GetMotionType(void);
};

int CameraMotionSystem::GetMotionType(void) {
    return m_motionType;
}
