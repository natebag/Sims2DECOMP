// FLAGS: -fno-schedule-insns
// SAnimator2::SetSkillName(AnimRef *) at 0x800693B8 (40B)

class AnimRef;

struct SAnimator2 {
    char pad_0[200];
    int m_field_C8;             // +200
    char pad_1[4];
    float m_field_D0;           // +208
    AnimRef* m_field_D4;         // +212
    char pad_2[0x544];           // to +1564
    int m_field_61C;             // +1564
    void SetSkillName(AnimRef* ref);
};

extern char g_skillDefaultFloat[16];  // force non-SDA lis+lfs pair

void SAnimator2::SetSkillName(AnimRef* ref) {
    int flags = m_field_61C;
    float def = *(float*)g_skillDefaultFloat;
    int zero = 0;
    flags |= 0x10000;
    m_field_C8 = zero;
    m_field_61C = flags;
    m_field_D0 = def;
    m_field_D4 = ref;
}
