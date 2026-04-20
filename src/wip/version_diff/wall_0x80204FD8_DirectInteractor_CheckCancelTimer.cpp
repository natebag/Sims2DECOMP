// WALL — 1-instruction order swap. ASM-PROCESSOR PERMUTER CANDIDATE.
// 0x80204FD8 InteractorModule::DirectInteractor::CheckCancelTimer (60B)
// Session 12 Track C Manipulator pioneer pass — parked by OpusWorker.
//
// DOL order (target):
//   fadds f0,f0,f12
//   fcmpu cr0,f0,f13      ← fcmpu BEFORE stfs
//   stfs f0,136(r11)
//   bgtlr
//
// GCC/SN output:
//   fadds f0,f0,f12
//   stfs f0,136(r11)      ← stfs BEFORE fcmpu
//   fcmpu cr0,f0,f13
//   bgtlr
//
// Tried:
//   (a) direct: if (t > thresh) return 1;
//   (b) goto fail + tentative result preloaded
//   (c) goto fail + split store paths (stfs twice — compiler dedup)
//   (d) explicit gt local: int gt = t>thresh; ... if (gt) ...
//   (e) float register pins on f0/f12/f13 — SN cc1plus rejects
//   (f) -fschedule-insns2 on + default — no change
//
// All forms: GCC emits stfs before fcmpu. Cannot pin float regs.
//
// Fix candidate: asm-processor permuter (swap adjacent fcmpu/stfs).

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
