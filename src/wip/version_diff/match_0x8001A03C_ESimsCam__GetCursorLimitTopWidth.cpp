/* ESimsCam::GetCursorLimitTopWidth(void) at 0x8001A03C (56B) */

struct ESimsCamCfg_GCLTW {
    char pad[40];
    float m_zoomMin;   // 40
    float m_zoomMax;   // 44
};

struct ESimsCamTable_TW {
    char pad[144];
    float m_min;   // 144
    float m_max;   // 148
};

extern ESimsCamTable_TW g_camTableTW;

struct ESimsCam_GCLTW {
    ESimsCamCfg_GCLTW* m_cfg;
    char pad[1092];
    float m_zoom;   // 1096
    float GetCursorLimitTopWidth();
};

float ESimsCam_GCLTW::GetCursorLimitTopWidth() {
    ESimsCamCfg_GCLTW* cfg = m_cfg;
    float t = (m_zoom - cfg->m_zoomMin) / (cfg->m_zoomMax - cfg->m_zoomMin);
    return t * (g_camTableTW.m_max - g_camTableTW.m_min) + g_camTableTW.m_min;
}
