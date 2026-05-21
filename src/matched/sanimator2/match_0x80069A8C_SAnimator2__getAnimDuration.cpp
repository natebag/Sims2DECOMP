// 0x80069A8C (80B) SAnimator2::getAnimDuration(ERAnim *)
// ASMPROC_fp_relabel: swap="0:13"
// ASMPROC_fp_relabel: swap="0:12"
// ASMPROC_replace_insn: match="lfd 1,8(1)" replacement="lfd 0,8(1)"
// ASMPROC_replace_insn: match="fsub 1,1,13" replacement="fsub 0,0,13"
// ASMPROC_replace_insn: match="frsp 1,1" replacement="frsp 1,0"

extern const float lbl_803D4C5C[3];

struct ERAnim {
    char pad_0[24];
    int m_field_18;    // 0x18
    char pad_1c[72];
    float m_field_64;  // 0x64
};

struct SAnimator2 {
    float getAnimDuration(ERAnim* anim);
};

float SAnimator2::getAnimDuration(ERAnim* anim) {
    float def = lbl_803D4C5C[0];
    if (!anim)
        return def;
    float f = (float)(anim->m_field_18 - 1);
    return f / anim->m_field_64;
}
