// 0x800160A8 CameraMotionSystem::SetMotionType(CameraMotionType) (8 B)
typedef unsigned CameraMotionType;
struct CameraMotionSystem { CameraMotionType m_motionType; void SetMotionType(CameraMotionType); };
void CameraMotionSystem::SetMotionType(CameraMotionType type) { m_motionType = type; }
