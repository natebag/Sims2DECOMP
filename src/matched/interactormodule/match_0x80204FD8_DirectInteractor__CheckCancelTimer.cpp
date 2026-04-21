// 0x80204FD8 InteractorModule::DirectInteractor::CheckCancelTimer (60B)
// S12 parked as "fcmpu-vs-stfs swap wall" — cracked in S13 via source-level
// preload of `thresh` into a named local before the fadds. This forces GCC
// to keep 3 live FP registers (f0=cancelTimer/t, f12=delta, f13=thresh)
// matching DOL's allocation. No asm-processor mutation needed.

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
