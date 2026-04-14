// 0x8005D014 SAnimator2::adjustAnimationPlayRates (56b)

struct ESim {
    char pad[0x334];
    char animator;
};

extern void SetAllTrackSpeed(void*, float);

struct SAnimator2 {
    char pad0[8];
    ESim* esim;
    char pad1[0xF0];
    float curRate;
    float newRate;
};

void SAnimator2_adjustPlayRates(SAnimator2* self) {
    if (self->newRate != self->curRate) {
        SetAllTrackSpeed(&self->esim->animator, self->curRate);
    }
}
