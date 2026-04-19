/* ESimsCam::GetCursorLimitDepth(void) at 0x8001A074 (56B) */

struct ESimsCamCfg_GCLD {
    char pad[40];
    float m_zoomMin;   // 40
    float m_zoomMax;   // 44
};

struct ESimsCamTable_D {
    char pad[152];
    float m_min;   // 152
    float m_max;   // 156
};

extern ESimsCamTable_D g_camTableD;

struct ESimsCam_GCLD {
    ESimsCamCfg_GCLD* m_cfg;
    char pad[1092];
    float m_zoom;   // 1096
    float GetCursorLimitDepth();
};

float ESimsCam_GCLD::GetCursorLimitDepth() {
    ESimsCamCfg_GCLD* cfg = m_cfg;
    float t = (m_zoom - cfg->m_zoomMin) / (cfg->m_zoomMax - cfg->m_zoomMin);
    return t * (g_camTableD.m_max - g_camTableD.m_min) + g_camTableD.m_min;
}
