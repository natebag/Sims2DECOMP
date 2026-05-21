// 0x802EE324 EAnimController::SetTrackBlendSmooth(EACTrack*, float, float, float) (108B)
//
// Sister overload of EAnimController::SetTrackBlendSmooth(eTrackFlags, ...) @ 0x802EE390.
// This is the EACTrack* pointer form — called from SetTrackBlend @ 0x802EE17C when the
// track's m_status indicates a smooth-blend transition.
//
// WALL CLASS: fcmpu-hoist over store-float run.
//   DOL emits `fcmpu cr0, f1, f0` BEFORE the 4-stfs argument-write sequence so the
//   cr0 set is bound tightly to the lfs that loaded f0. GCC's RTL scheduler sees
//   no data dependency between fcmpu and the stfs writes and moves the fcmpu to
//   the end of the basic block, just before the conditional branch that consumes
//   cr0. Same number of instructions, same semantics — pure byte-position wall.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_hoist_fcmpu: occurrence=1
// ASMPROC_swap_adj: a=stb b=lis which=first
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=stb b=lfs which=first

class EACTrack {
public:
    char pad_0[14];
    unsigned char m_status;  // 14
    char pad_15[69];         // → 84
    float m_field_54;        // 84 (0x54)
    float m_field_58;        // 88 (0x58)
    char pad_5C[8];
    float m_field_64;        // 100 (0x64)
    float m_field_68;        // 104 (0x68)
    char pad_6C[52];
    unsigned char m_byte_A0; // 160 (0xA0)
    char pad_A1[7];
    int m_field_A8;          // 168 (0xA8)
};

extern const float lbl_805EE2C4[3];

class EAnimController {
public:
    void SetTrackBlendSmooth(EACTrack* track, float blend, float a, float b);
    void SetTrackActive(EACTrack* track, bool active);
};

void EAnimController::SetTrackBlendSmooth(EACTrack* track, float blend, float a, float b)
{
    if (track == 0) return;
    if (track->m_field_A8 != 1) return;
    if (blend == track->m_field_64) return;
    track->m_byte_A0 = 2;
    bool unchanged = (blend == lbl_805EE2C4[0]);
    track->m_field_58 = b;
    track->m_field_68 = a;
    track->m_field_64 = blend;
    track->m_field_54 = a;
    if (unchanged) return;
    SetTrackActive(track, true);
}
