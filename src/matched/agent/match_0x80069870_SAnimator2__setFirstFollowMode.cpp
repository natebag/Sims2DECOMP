// 0x80069870 SAnimator2::setFirstFollowMode(eFollowMode) (116B)
// Pattern: flag + guarded state change + blend-out call
class EACTrack;
class EAnimController {
public:
    void BlendAllOutgoingTracks(float a, float b, bool c);
};

extern const float gFirstFollow_f1[3];
extern const float gFirstFollow_f2[3];

struct SAnimator2 {
    char pad[8];
    void* m_inner;
    char pad_12[4];
    int m_field_16;
    char pad_20[4];
    int m_field_24;
    char pad_28[1536];
    int m_flags;
    char pad_1568[72];
    EACTrack* m_track;
    void setFirstFollowMode(int mode);
};

void SAnimator2::setFirstFollowMode(int mode) {
    m_field_16 = 1;
    if (m_field_24 <= 5) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        m_field_24 = mode;
        m_flags = m_flags & ~0x7E;
        ctrl->BlendAllOutgoingTracks(gFirstFollow_f1[0], gFirstFollow_f2[0], true);
        m_track = 0;
    }
}
