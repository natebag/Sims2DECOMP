// 0x80069920 SAnimator2::setFollowEnd (120B)
// Pattern: bitmask flags clear + state/rate assign + SDA2-mixed float trio + track null
class EACTrack;
class EAnimController {
public:
    void SetTrackBlendSmooth(EACTrack* t, float a, float b, float c);
};

extern const float gFollowEnd_f1[3];  // non-SDA
extern const float gFollowEnd_f3[3];  // non-SDA
extern const float gFollowEnd_f2;     // SDA2

struct SAnimator2 {
    char pad[8];
    void* m_inner;       // offset 8
    char pad_12[12];
    int m_state;         // offset 24
    char pad_28[248];
    float m_rate;        // offset 276
    char pad_280[1284];
    int m_flags;         // offset 1564
    char pad_1568[72];
    EACTrack* m_track;   // offset 1640
    void setFollowEnd();
};

void SAnimator2::setFollowEnd() {
    m_flags = m_flags & ~0x5E;
    m_state = 4;
    m_rate = gFollowEnd_f1[0];
    if (m_track != 0) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        ctrl->SetTrackBlendSmooth(m_track, gFollowEnd_f1[0], gFollowEnd_f2, gFollowEnd_f3[0]);
        m_track = 0;
    }
}
