// 0x80069A8C SAnimator2::getAnimDuration(ERAnim *) (80B)
// Pattern: hoisted default-return const + null-guard + classic PPC int-to-float magic divide.
// (len-1)/rate via signed-int xoris/stw/lfd/fsub-magic + frsp + fdivs.

extern const float gAnimDur_const1[3];   // non-SDA float const at 0x803D4C5C
extern const double gAnimDur_magic;       // non-SDA double at 0x803D4C60 (int-to-float bias)

struct ERAnim {
    char pad_0[24];
    int m_length;     // 24 (0x18)
    char pad_28[72];
    float m_rate;     // 100 (0x64)
};

class SAnimator2 {
public:
    float getAnimDuration(ERAnim* anim);
};

float SAnimator2::getAnimDuration(ERAnim* anim) {
    float ret = gAnimDur_const1[0];
    if (anim != 0) {
        int len = anim->m_length;
        float rate = anim->m_rate;
        ret = (float)(len - 1);
        ret /= rate;
    }
    return ret;
}
