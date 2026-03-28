/* 0x80058F80 (12 bytes) - OptionsRecon::RestorePrefsForOnline(void) */
class OptionsRecon {
public:
    char pad_000[0x10];
    int m_field_010;
    char pad_014[0x3C];
    int m_field_050;
    void RestorePrefsForOnline(void);
};

void OptionsRecon::RestorePrefsForOnline(void) {
    m_field_010 = m_field_050;
}
