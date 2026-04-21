// asm-processor input: 0x80204FD8 InteractorModule::DirectInteractor::CheckCancelTimer (60B).
// Source: moved/adapted from src/wip/version_diff/wall_0x80204FD8_*.cpp, OpusWorker S12 pioneer.
//
// Wall: combined adjacent-reorder + register-allocation. SN cc1plus emits:
//   fadds; stfs; lfs thresh; fcmpu
// DOL wants:
//   lfs thresh (early); fadds; fcmpu; stfs
//
// Solution (source-level only — no asm-processor directive needed):
//   Preload `thresh` into a named local BEFORE the fadds. This forces GCC to
//   load the threshold early AND keep it in a separate register (f13) from
//   delta (f12) and cancelTimer (f0) — matching DOL's 3-FP-register
//   allocation. With that preload, GCC natively emits fadds, fcmpu, stfs
//   in the DOL-matching order. Cracked 2026-04-21 by OpusWorker (Phase 2).

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
        float curr = self->m_cancelTimer;
        float delta = g_cancelDelta;
        float thresh = *(float*)g_cancelThreshBuf;
        float t = curr + delta;
        int result = 1;
        self->m_cancelTimer = t;
        if (t > thresh) return result;
    }
fail:
    return 0;
}
