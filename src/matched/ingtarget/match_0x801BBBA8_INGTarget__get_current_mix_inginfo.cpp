// INGTarget::get_current_mix_inginfo(void) - 0x801BBBA8 (72 bytes)
//
// Tech #73 sibling-batch follow-up to get_current_inginfo @ 0x801BBB60.
// Structurally similar but: 4-slot array of 8-byte entries, m_mix_count
// at 0x450 (not 0x44C), explicit add. record-form pointer-test.
//
// FLAGS: -msdata=eabi -G 8

struct MixInfo {
    int m_first;
    int m_second;
};

struct INGTarget_mix {
    char pad_0[0x1E0];
    MixInfo m_mix_array[4];
    char pad_after[0x450 - 0x1E0 - 4 * 8];
    unsigned int m_mix_count;

    MixInfo* get_current_mix_inginfo();
};

MixInfo* INGTarget_mix::get_current_mix_inginfo() {
    if (m_mix_count > 3) return 0;
    MixInfo* mig = (MixInfo*)((unsigned long)this + 480 + m_mix_count * 8);
    if (mig == 0) return 0;
    if (mig->m_first == 0) return 0;
    return mig;
}
