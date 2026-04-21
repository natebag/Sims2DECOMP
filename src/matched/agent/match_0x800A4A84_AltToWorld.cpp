// 0x800A4A84 (44B) AltToWorld(float &)
// AltToIso(ref) * const_scale.

float AltToIso(float& alt);

extern char s_altToWorldScale[];

float AltToWorld(float& alt) {
    return AltToIso(alt) * *(float*)s_altToWorldScale;
}
