/* ESimsCam::GetCursorSpeed(void) at 0x8001A00C (48B) */

struct ESimsCamCfg_GCS {
    char pad[40];
    float m_zoomMin;    // 40
    float m_zoomMax;    // 44
    char pad2[40];
    float m_speedMin;   // 88
    float m_speedMax;   // 92
};

struct ESimsCam_GCS {
    ESimsCamCfg_GCS* m_cfg;
    char pad[1092];
    float m_zoom;       // offset 1096
    float GetCursorSpeed();
};

float ESimsCam_GCS::GetCursorSpeed() {
    ESimsCamCfg_GCS* cfg = m_cfg;
    float t = (m_zoom - cfg->m_zoomMin) / (cfg->m_zoomMax - cfg->m_zoomMin);
    return t * (cfg->m_speedMax - cfg->m_speedMin) + cfg->m_speedMin;
}
