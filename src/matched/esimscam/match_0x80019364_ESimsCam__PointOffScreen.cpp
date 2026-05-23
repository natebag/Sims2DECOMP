/* ESimsCam::PointOffScreen(EVec3 &) at 0x80019364 (52B) */

struct EVec3_POS { float x, y, z; };

struct ESimsCamCfg_POS {
    char pad[160];
    float m_left;
    float m_right;
    float m_top;
    float m_bottom;
};

struct ESimsCam_POS {
    ESimsCamCfg_POS* m_cfg;
    int PointOutsideScreenRect(EVec3_POS& v, float left, float right, float top, float bottom);
    int PointOffScreen(EVec3_POS& v);
};

int ESimsCam_POS::PointOffScreen(EVec3_POS& v) {
    ESimsCamCfg_POS* cfg = m_cfg;
    return PointOutsideScreenRect(v, cfg->m_left, cfg->m_right, cfg->m_top, cfg->m_bottom);
}
