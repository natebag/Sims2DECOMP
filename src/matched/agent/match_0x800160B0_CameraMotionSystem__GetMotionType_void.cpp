// 0x800160B0 CameraMotionSystem::GetMotionType(void) (8 B)
typedef unsigned CameraMotionType;
struct CameraMotionSystem { CameraMotionType m_motionType; CameraMotionType GetMotionType(); };
CameraMotionType CameraMotionSystem::GetMotionType() { return m_motionType; }
