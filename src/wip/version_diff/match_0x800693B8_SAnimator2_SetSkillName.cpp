// 0x800693B8 SAnimator2::SetSkillName (40b)

struct AnimRef;

struct SAnimator2 {
    int m_flags;
    int m_skillTrackIndex;
    float m_blendTime;
    AnimRef* m_currentAnimRef;
    void SetSkillName(AnimRef* ref);
};

void SAnimator2::SetSkillName(AnimRef* ref) {
    m_flags |= 0x00010000;
    m_skillTrackIndex = 0;
    m_blendTime = 0.0f;
    m_currentAnimRef = ref;
}
