// 0x800697D8 SAnimator2::DetachMonitoredTrack (84B)
// Pattern: SDA2-mixed float trio (2 non-SDA + 1 SDA2) + animcontroller call + pointer null
class EACTrack;
class EAnimController {
public:
    void SetTrackBlendSmooth(EACTrack* t, float a, float b, float c);
};

extern const float gF_DetachTrack_1[3];  // non-SDA (large)
extern const float gF_DetachTrack_3[3];  // non-SDA
extern const float gF_DetachTrack_2;     // SDA2

struct SAnimator2 {
    char pad[8];
    void* m_inner;
    char pad2[1628];
    EACTrack* m_monitorTrack;
    void DetachMonitoredTrack();
};

void SAnimator2::DetachMonitoredTrack() {
    EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
    ctrl->SetTrackBlendSmooth(m_monitorTrack, gF_DetachTrack_1[0], gF_DetachTrack_2, gF_DetachTrack_3[0]);
    m_monitorTrack = 0;
}
