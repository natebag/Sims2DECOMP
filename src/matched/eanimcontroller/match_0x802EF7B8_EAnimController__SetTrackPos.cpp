// 0x802EF7B8 EAnimController::SetTrackPos(EACTrack *, float, bool) (104B)
// Pattern: null + state==1 guard + int-to-float magic (len-1) * pos + conditional SDA-int store.
// Same int-to-float idiom as getAnimDuration; bool check pre-set then late conditional store.

struct AnimObj { char pad[24]; int m_length; };

class EACTrack {
public:
    char pad_0[56];
    int m_field_38;                // 56 (0x38)
    char pad_60[4];
    float m_field_40;              // 64 (0x40)
    char pad_68[56];
    AnimObj* m_animObj;            // 124 (0x7C)
    char pad_128[40];
    int m_field_A8;                // 168 (0xA8)
};

extern int g_setTrackPosVal;       // SDA at r13-26812

class EAnimController {
public:
    void SetTrackPos(EACTrack* track, float pos, bool flag);
};

void EAnimController::SetTrackPos(EACTrack* track, float pos, bool flag) {
    if (track == 0) return;
    if (track->m_field_A8 != 1) return;
    int len = track->m_animObj->m_length;
    track->m_field_40 = pos * (float)(len - 1);
    if (flag) {
        track->m_field_38 = g_setTrackPosVal;
    }
}
