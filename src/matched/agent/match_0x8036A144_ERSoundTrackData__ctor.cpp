// 0x8036A144 ERSoundTrackData::ERSoundTrackData(void) (80B)
//
// EResource-derived ctor, sister to REffectsEmitter @ 0x8036A7B4.
//
// Recipe (same as REffectsEmitter, PLUS frame-pad for the 24B vs 16B stack diff):
//   - Uniform `*(volatile int*)` cast for all stores (even vt pointer cast to int).
//     Keeps volatile-ordering chain intact so vt store stays at source-listed position.
//   - `volatile int _frame_pad[2]` local forces GCC to allocate an extra 8B stack
//     to match DOL's 24B frame (vs the 16B GCC picks without it).
//   - 2 swap_adj for prologue reorder (li-lis swap + stw-la swap).
//   - Sub-base `char* sub = this + 28; sub+4` pattern for the +32 store via indirect.
//
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=stw b=la which=first

extern char ERSoundTrackData_vt[];

class EResource {
public:
    EResource();
};

class ERSoundTrackData : public EResource {
public:
    ERSoundTrackData();
};

ERSoundTrackData::ERSoundTrackData() {
    volatile int _frame_pad[2];
    (void)_frame_pad;
    *(volatile int*)((char*)this + 20) = 0;
    *(volatile int*)((char*)this + 0)  = (int)ERSoundTrackData_vt;
    *(volatile int*)((char*)this + 24) = 0;
    char* sub = (char*)this + 28;
    *(volatile int*)(sub + 4) = 0;
}
