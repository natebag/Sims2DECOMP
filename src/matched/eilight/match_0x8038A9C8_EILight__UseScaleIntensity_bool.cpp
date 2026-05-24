// 0x8038A9C8 EILight::UseScaleIntensity(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x5ac(5)"

struct EILight {
    void UseScaleIntensity();
};

void EILight::UseScaleIntensity() {
}
