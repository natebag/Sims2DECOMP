// 0x8001d2dc CameraDirector::SetFOV(float) (96B)
// Converts fov rad->deg via const 57.2957763671875 (lis+lfs non-SDA pair).
// Updates inner->m_fovMax / m_fovMin clamps with NaN-loose `>` and `<`.
// 3x re-load of m_field170 (the stfs invalidates pointer caching).

struct ESimsCamInner {
    char pad[0x60];
    float m_fovMin;  // 0x60
    float m_fovMax;  // 0x64
};

class ESimsCam {
public:
    ESimsCamInner* m_inner;
    void SetFov(float);
};

class CameraDirector {
public:
    char pad[0x170];
    ESimsCam* m_camera;  // 0x170
    void SetFOV(float fov);
};

extern char g_camRad2Deg[16];  // non-SDA: forces lis+lfs

void CameraDirector::SetFOV(float fov) {
    fov *= *reinterpret_cast<const float*>(&g_camRad2Deg);
    if (fov > m_camera->m_inner->m_fovMax) m_camera->m_inner->m_fovMax = fov;
    if (fov < m_camera->m_inner->m_fovMin) m_camera->m_inner->m_fovMin = fov;
    m_camera->SetFov(fov);
}
