// SAnimator2::IsSkillIdleAnimRunning() at 0x8005D6A0 (52 bytes)
// Reads m_idx from helper at this->[8]+820. If idx != -1, looks up flags
// in 176-byte stride array at helper+68, returns bit 4 of flags.

typedef unsigned char u8;

int SAnimator2_IsSkillIdleAnimRunning(u8* self) {
    u8* obj = *(u8**)(self + 8);
    u8* helper = obj + 820;
    int idx = *(int*)(helper + 8);
    int flags;
    if (idx != -1) {
        u8* base = *(u8**)(helper + 68);
        flags = *(int*)(base + idx * 176 + 48);
    } else {
        flags = 0;
    }
    return (flags >> 5) & 1;
}
