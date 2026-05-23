/* ESimsCam::CalcTiltFromZoom(float) at 0x80017A90 (44B) */

struct ESimsCamCfg_CTFZ {
    char pad[40];
    float m_zoomMin;    // 40
    float m_zoomMax;    // 44
    char pad2[8];
    float m_tiltMin;    // 56
    float m_tiltMax;    // 60
};

struct ESimsCam_CTFZ {
    ESimsCamCfg_CTFZ* m_cfg;
    float CalcTiltFromZoom(float zoom);
};

float ESimsCam_CTFZ::CalcTiltFromZoom(float zoom) {
    ESimsCamCfg_CTFZ* cfg = m_cfg;
    float t = (zoom - cfg->m_zoomMin) / (cfg->m_zoomMax - cfg->m_zoomMin);
    return t * (cfg->m_tiltMax - cfg->m_tiltMin) + cfg->m_tiltMin;
}
