/* OptionsRecon::PreservePrefsForOnline(void) at 0x80058EE8 (20B) */

extern int g_prefsPreserved;

struct OptionsRecon {
    char pad_0[0x10];
    int m_field_10;
    char pad_14[0x3C];
    int m_field_50;

    void PreservePrefsForOnline(void);
};

void OptionsRecon::PreservePrefsForOnline(void) {
    m_field_50 = m_field_10;
    g_prefsPreserved = 1;
}
