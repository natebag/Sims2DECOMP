// 0x80366D50 ERAmbientScore::ERAmbientScore(void) (112B)
//
// EResource-derived ctor — third instance of the cluster recipe, larger
// field list (13 stores including 3 stb + 10 stw).
//
// Recipe (unified with REffectsEmitter + ERSoundTrackData):
//   - Uniform `*(volatile int*)` (and `*(volatile char*)` for byte fields).
//   - `volatile int _frame_pad[2]` for 24B stack frame.
//   - 2 swap_adj for prologue reorder.
//   - Sub-base `int* sub52 = this + 52; sub52[1]` for the +56 store.
//
// This is now a **3-INSTANCE-CANDIDATE recipe** — same 4-directive structure
// (uniform-volatile + frame-pad + 2 swap_adj) cracks all three EResource-
// derived ctors with field-order divergence.
//
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=stw b=la which=first

extern char ERAmbientScore_vt[];

class EResource {
public:
    EResource();
};

class ERAmbientScore : public EResource {
public:
    ERAmbientScore();
};

ERAmbientScore::ERAmbientScore() {
    volatile int _frame_pad[2];
    (void)_frame_pad;
    char* p = (char*)this;
    *(volatile int*)(p + 44) = 0;
    *(volatile int*)(p + 0)  = (int)ERAmbientScore_vt;
    int* sub52 = (int*)(p + 52);
    *(volatile int*)(p + 48) = 0;
    *(volatile int*)(sub52 + 1) = 0;
    *(volatile char*)(p + 42) = 0;
    *(volatile int*)(p + 20) = 0;
    *(volatile int*)(p + 24) = 0;
    *(volatile int*)(p + 28) = 0;
    *(volatile int*)(p + 36) = 0;
    *(volatile int*)(p + 32) = 0;
    *(volatile char*)(p + 40) = 0;
    *(volatile char*)(p + 41) = 0;
}
