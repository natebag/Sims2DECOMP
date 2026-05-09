// 0x800169E8 ESimsCam::SetFov(float) (52B)
// VERSION_DIFF: FP register allocation + load interleave.
//   DOL load order: f11=96, f13=100, f10=40, f0=44 (4 registers: f0/f10/f11/f13)
//   GCC compiled:   f11=96, f0=40,  f12=100, f13=44 (4 registers: f0/f11/f12/f13)
// Source matches algebraically; compiler picks different FP registers.
// Multiple source forms tried (var reorder, factored out subterms).
// Track-I: needs fp_relabel mutator (f12->f10 + f13->f0 + f0->f10 etc.)
// or coordinated fp-register pinning. Park for MutatorSmith.

struct ESimsCamInner {
    char pad[40];
    float m_zoomMin;   // 40
    float m_zoomMax;   // 44
    char pad2[48];
    float m_fovMin;    // 96
    float m_fovMax;    // 100
};

struct ESimsCam {
    ESimsCamInner* m_inner;
    char pad[1092];
    float m_curZoom;
    void SetFov(float);
};

void ESimsCam::SetFov(float fov) {
    ESimsCamInner* inner = this->m_inner;
    float fovMin = inner->m_fovMin;
    float fovMax = inner->m_fovMax;
    float zoomMin = inner->m_zoomMin;
    float zoomMax = inner->m_zoomMax;
    this->m_curZoom = ((fov - fovMin) * (zoomMax - zoomMin) + zoomMin * (fovMax - fovMin)) / (fovMax - fovMin);
}
