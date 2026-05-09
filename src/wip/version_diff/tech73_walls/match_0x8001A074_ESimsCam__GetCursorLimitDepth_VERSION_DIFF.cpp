// ESimsCam::GetCursorLimitDepth(void) - 0x8001A074 (56 bytes)
// Linear interpolation of cursor depth from zoom range.
//
// VERSION_DIFF: Track-I fp register allocation wall.
// Got SDA base + load order + fmadds form correct, BUT:
//   - DOL: a→f12, b→f1, t→f13. fmadds f1,f1,f13,f12 (b-a in f1).
//   - Mine: a→f11, b→f13, t→f1. fmadds f1,f13,f1,f11 (b-a in f13).
// Only diff is which fp registers carry which values. Identical
// instruction count, identical structure, identical SDA layout.
//
// 4 source variants tested: explicit locals, single-expression,
// inline-b-in-return, table-base-first. All produce same regalloc
// outcome. GCC consistently puts m_zoom_curr in f1 (return reg)
// because it's the longest-lived value chain; DOL keeps return reg
// free until the final `b` load.
//
// MutatorSmith candidate: fp-regalloc-rename mutator (would also
// help filter_wallpaper, AAR, PADIsBarrel walls).
//
// FLAGS: -msdata=eabi -G 8

extern char g_camDepthTable[256];

struct CamCore {
    char pad_0[40];
    float m_near;
    float m_far;
};

struct ESimsCam {
    CamCore* m_cam;
    char pad_4[1096 - 4];
    float m_zoom_curr;

    float GetCursorLimitDepth();
};

float ESimsCam::GetCursorLimitDepth() {
    char* tbl = g_camDepthTable;
    CamCore* cam = m_cam;
    float t = m_zoom_curr;
    float n = cam->m_near;
    float f = cam->m_far;
    t = t - n;
    float a = *(float*)(tbl + 152);
    f = f - n;
    t = t / f;
    return (*(float*)(tbl + 156) - a) * t + a;
}
