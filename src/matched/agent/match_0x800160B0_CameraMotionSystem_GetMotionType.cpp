// 0x800160B0 (8B) CameraMotionSystem::GetMotionType(void)
// Getter for field at offset 0x0.

class CameraMotionSystem {
public:
    int m_field_0;
    int GetMotionType(void);
};

int CameraMotionSystem::GetMotionType(void) {
    return m_field_0;
}
