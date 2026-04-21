// asm-processor input: 0x80204FD8 InteractorModule::DirectInteractor::CheckCancelTimer (60B).
// Source: moved/adapted from src/wip/version_diff/wall_0x80204FD8_*.cpp, OpusWorker S12 pioneer.
//
// Wall: two-step adjacent-instruction reorder. SN cc1plus emits:
//   stfs 13,136(11)                      ← store
//   lfs  0,g_cancelThreshBuf@l(9)        ← load thresh
//   fcmpu 0,13,0                         ← compare
// DOL wants:
//   lfs  0,g_cancelThreshBuf@l(9)        ← load thresh EARLY
//   fcmpu 0,13,0                         ← compare
//   stfs 13,136(11)                      ← store LATE
//
// Reached via two adjacent-pair swaps applied in order:
//   (a) swap (stfs, lfs)   → moves the thresh-load above the store
//   (b) swap (stfs, fcmpu) → moves the compare above the store
//
// ASMPROC_swap_adj: a=stfs b=lfs which=first
// ASMPROC_swap_adj: a=stfs b=fcmpu which=first

extern float g_cancelDelta;
extern char g_cancelThreshBuf[16];

struct DirectInteractor {
    char pad_00[0x84];
    int m_state;
    float m_cancelTimer;
};

int InteractorModule_DirectInteractor_CheckCancelTimer(DirectInteractor* self) {
    if (self->m_state != 1) goto fail;
    {
        float t = self->m_cancelTimer + g_cancelDelta;
        int result = 1;
        self->m_cancelTimer = t;
        if (t > *(float*)g_cancelThreshBuf) return result;
    }
fail:
    return 0;
}
