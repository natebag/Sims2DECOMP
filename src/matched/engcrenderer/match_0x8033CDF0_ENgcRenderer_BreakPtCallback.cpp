// FLAGS: -fno-schedule-insns
// 0x8033CDF0 ENgcRenderer::BreakPtCallback(void) (48B)

extern int g_brkSecondary;  // SDA @ -26148
extern int g_brkPrimary;    // SDA @ -26152

extern "C" void GXDisableBreakPt();

struct ENgcRenderer {
    static void BreakPtCallback();
};

void ENgcRenderer::BreakPtCallback() {
    g_brkSecondary = 1;
    g_brkPrimary = 0;
    GXDisableBreakPt();
}
