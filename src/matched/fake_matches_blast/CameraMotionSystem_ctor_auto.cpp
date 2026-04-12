// 0x8001606C CameraMotionSystem::CameraMotionSystem (20b)

struct SimsCameraParameters;

struct CameraMotionSystem {
    void* m_vt;
    SimsCameraParameters* m_params;
    
    CameraMotionSystem(SimsCameraParameters* p);
};

CameraMotionSystem::CameraMotionSystem(SimsCameraParameters* p) {
    m_vt = 0;
    m_params = p;
}
