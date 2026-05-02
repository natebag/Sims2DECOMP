// AwarenessManager::AwarenessAutoRunCheck(float) - 0x80012258 (88 bytes)
// Tech #73 NEAR-MISS — fmr/bnelr Track-I walls.
//
// Got bnslr+cror+lis/lfs pattern correct (Tech #73 working) but TWO scheduler
// asymmetries vs DOL persist regardless of source form:
//
// (1) fmr f0,f1 prologue: DOL preserves arg into f0 early so f1 can be reused
//     for constant loads in BOTH branches. Mine keeps arg in f1, loads constant
//     into f0 each branch → fcmpu reg order REVERSED (cr0,f1,f0 vs cr0,f0,f1).
//     Tested with `float a = arg;` named local — no effect.
//
// (2) bnelr early-exit: DOL uses bnelr after cmpwi r0,1; mine uses beq
//     forward-jump + redundant li r3,0; blr block. Same situation as
//     filter_wallpaper — GCC's basic-block placement does not honor the
//     source-level early-return form when r3=0 was preset 30+ bytes earlier.
//
// Both differences are Track-I scheduler/reg-alloc walls — NOT source-coax
// addressable. MutatorSmith candidate for register-rename + branch-direction
// flip mutator. 88B fp-multibranch above Tech #73's effective scope ceiling.
//
// FLAGS: -msdata=eabi -G 8

extern int g_aar_sda_flag;
extern char g_aar_thresh_a_buf[16];
extern char g_aar_thresh_b_buf[16];

struct AwarenessManager {
    unsigned int m_flags;
    int AwarenessAutoRunCheck(float arg);
};

int AwarenessManager::AwarenessAutoRunCheck(float arg) {
    float a = arg;
    int r = 0;
    if (m_flags & 1) {
        float t_a = *(float*)g_aar_thresh_a_buf;
        if (a >= t_a) r = 1;
        return r;
    }
    if (g_aar_sda_flag != 1) return r;
    float t_b = *(float*)g_aar_thresh_b_buf;
    if (a >= t_b) r = 1;
    return r;
}
