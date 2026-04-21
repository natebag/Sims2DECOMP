// asm-processor pioneer input: 0x8001A03C ESimsCam::GetCursorLimitTopWidth (56B).
// Cat 2 wall: FP-register coloring. SN cc1plus picks f0/f12/f13/f11 where DOL
// picks f13/f11/f0/f12 — identical instruction order, swapped register labels.
// Single force_reg would break the chain (each reg appears 3-4 times). Needs
// atomic bidirectional relabel.
//
// ASMPROC_fp_relabel: swap=0:13,11:12

struct ESimsCamCfg_GCLTW {
    char pad[40];
    float m_zoomMin;
    float m_zoomMax;
};

struct ESimsCamTable_TW {
    char pad[144];
    float m_min;
    float m_max;
};

extern ESimsCamTable_TW g_camTableTW;

struct ESimsCam_GCLTW {
    ESimsCamCfg_GCLTW* m_cfg;
    char pad[1092];
    float m_zoom;
    float GetCursorLimitTopWidth();
};

float ESimsCam_GCLTW::GetCursorLimitTopWidth() {
    ESimsCamCfg_GCLTW* cfg = m_cfg;
    float t = (m_zoom - cfg->m_zoomMin) / (cfg->m_zoomMax - cfg->m_zoomMin);
    return t * (g_camTableTW.m_max - g_camTableTW.m_min) + g_camTableTW.m_min;
}
