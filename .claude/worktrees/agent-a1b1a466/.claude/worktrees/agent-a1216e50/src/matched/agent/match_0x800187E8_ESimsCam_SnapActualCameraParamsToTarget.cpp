struct CameraParams {
    float a, b, c, d, e, f;
};

struct ESimsCam {
    char pad[0x43C];
    CameraParams m_target;
    CameraParams m_actual;

    void SnapActualCameraParamsToTarget();
};

void ESimsCam::SnapActualCameraParamsToTarget() {
    m_actual = m_target;
}
