// 0x8001A03C ESimsCam::GetCursorLimitTopWidth (56B)
// S12 parked as Cat 2 FP-coloring wall.
// S13 Track I wall #2: cracked via asm-processor fp_relabel (swap=0:13,11:12).
//
// cc1plus picks {f0, f12, f13, f11} for the fmadds chain registers where
// DOL picks {f13, f11, f0, f12} — a global, self-consistent rotation
// across 8+ instructions. fp_relabel applies the swap atomically.
//
// ASMPROC_fp_relabel: swap=0:13,11:12

struct ESimsCamCfg {
    char pad[40];
    float m_zoomMin;
    float m_zoomMax;
};

struct ESimsCamTable {
    char pad[144];
    float m_min;
    float m_max;
};

extern ESimsCamTable g_camTableTW;

struct ESimsCam {
    ESimsCamCfg* m_cfg;
    char pad[1092];
    float m_zoom;
    float GetCursorLimitTopWidth();
};

float ESimsCam::GetCursorLimitTopWidth() {
    ESimsCamCfg* cfg = this->m_cfg;
    float t = (this->m_zoom - cfg->m_zoomMin) / (cfg->m_zoomMax - cfg->m_zoomMin);
    return t * (g_camTableTW.m_max - g_camTableTW.m_min) + g_camTableTW.m_min;
}
