// CameraMotionSystem::MoveCamera(void) - 0x8001621C (60 bytes)

class CameraMotionSystem {
public:
    int m_motionType;    // 0
    
    void MoveCamera(void);
    void SnapCamera(void);      // 0x80016110
    void RubberBandMove(void);  // 0x8001639C
};

void CameraMotionSystem::MoveCamera(void) {
    if (m_motionType == 0 || m_motionType == 1) {
        RubberBandMove();
    } else {
        SnapCamera();
    }
}
