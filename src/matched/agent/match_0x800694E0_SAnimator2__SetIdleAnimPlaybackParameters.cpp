// 0x800694E0 SAnimator2::SetIdleAnimPlaybackParameters(EACTrack*) (76B)
// Pattern: null-arg guard + struct offset call + byte store
struct EACTrack { char pad[13]; unsigned char f13; };
struct Inner { char pad[820]; };
extern void SetParam(void* inner, EACTrack* t, float f);

struct SAnimator2 {
    char pad[8];
    Inner* m_inner;
    char pad2[240];  // offset 12 to 252
    float m_rate;    // offset 252
    void SetIdleAnimPlaybackParameters(EACTrack* t);
};

void SAnimator2::SetIdleAnimPlaybackParameters(EACTrack* t) {
    if (t == 0) return;
    SetParam((char*)m_inner + 820, t, m_rate);
    t->f13 = 0;
}
