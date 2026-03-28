struct SocialEffect {
    char pad[0x0C];
    int m_mode;
};

SocialEffect* GetSocialEffect(void*);
void SetSocialEffect(SocialEffect*, int);

void TurnOffSocialModeEffects(void* mgr) {
    if (mgr) {
        SocialEffect* effect = GetSocialEffect(mgr);
        if (effect) {
            if (effect->m_mode != 1) {
                SetSocialEffect(effect, 0);
            }
        }
    }
}
