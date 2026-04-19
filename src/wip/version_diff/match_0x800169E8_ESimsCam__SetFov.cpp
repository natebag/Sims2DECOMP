/* ESimsCam::SetFov(float) at 0x800169E8 (52B) */

struct ESimsCamCfg_SFV {
    char pad[40];
    float m_zoomMin;  // offset 40
    float m_zoomMax;  // offset 44
    char pad2[48];
    float m_fovMin;   // offset 96
    float m_fovMax;   // offset 100
};

struct ESimsCam_SFV {
    ESimsCamCfg_SFV* m_cfg;
    char pad[1092];
    float m_zoom;     // offset 1096
    void SetFov(float fov);
};

void ESimsCam_SFV::SetFov(float fov) {
    ESimsCamCfg_SFV* cfg = m_cfg;
    float fovMin = cfg->m_fovMin;
    float fovMax = cfg->m_fovMax;
    float zoomMin = cfg->m_zoomMin;
    float zoomMax = cfg->m_zoomMax;
    float fovRange = fovMax - fovMin;
    m_zoom = (fov - fovMin) * (zoomMax - zoomMin) / fovRange + zoomMin;
}
