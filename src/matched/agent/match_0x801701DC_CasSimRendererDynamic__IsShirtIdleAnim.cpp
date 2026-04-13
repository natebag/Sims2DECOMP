// 0x801701DC CasSimRendererDynamic::IsShirtIdleAnim(unsigned int) (64B)

struct AnimData {
    char pad1[0x28];
    unsigned int m_anim1;   // 0x28
    unsigned int m_anim2;   // 0x2C
    unsigned int m_anim3;   // 0x30
    char pad2[0x2C];
    unsigned int m_anim4;   // 0x60
};

struct CasSimRendererDynamic {
    char pad[0x224];
    AnimData* m_animData;

    int IsShirtIdleAnim(unsigned int anim);
};

int CasSimRendererDynamic::IsShirtIdleAnim(unsigned int anim) {
    int r = 0;
    AnimData* data = m_animData;
    if (anim == data->m_anim1 || anim == data->m_anim4 || anim == data->m_anim2 || anim == data->m_anim3)
        r = 1;
    return r;
}
