/* CameraMotionSystem::CameraMotionSystem(SimsCameraParameters *) at 0x8001606C (20B) */

struct CameraMotionSystem {
    int m_motionType;
    int* m_params;

    CameraMotionSystem(int* params);
};

CameraMotionSystem::CameraMotionSystem(int* params) {
    m_motionType = 0;
    m_params = params;
}
