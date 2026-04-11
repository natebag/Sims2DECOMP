/* OptionsRecon::PreservePreferences(void) at 0x80058E5C (140B) */

extern int g_preferencesPreserved;

struct OptionsRecon {
    int m_musicVol;
    int m_sfxVol;
    int m_voiceVol;
    char pad_0C[4];
    int m_screenMode;
    int m_brightness;
    int m_contrast;
    char m_vibration;
    char m_widescreen;
    char m_subtitles;
    char m_field1F;
    char m_field20;
    char pad_21[3];
    int m_field24;
    char m_field28;
    char m_field29;
    char pad_2A[2];
    int m_savedMusicVol;
    int m_savedSfxVol;
    int m_savedVoiceVol;
    int m_savedScreenMode;
    int m_savedBrightness;
    int m_savedContrast;
    int m_savedField44;
    char m_savedVibration;
    char m_savedWidescreen;
    char m_savedSubtitles;
    char m_savedField4B;
    char m_savedField4C;
    char m_savedField4D;
    char m_savedField4E;

    void PreservePreferences(void);
};

void OptionsRecon::PreservePreferences(void) {
    m_savedMusicVol = m_musicVol;
    m_savedSfxVol = m_sfxVol;
    m_savedVoiceVol = m_voiceVol;
    m_savedScreenMode = m_screenMode;
    m_savedVibration = m_vibration;
    m_savedWidescreen = m_widescreen;
    m_savedSubtitles = m_subtitles;
    m_savedField4B = m_field1F;
    m_savedField4C = m_field20;
    m_savedBrightness = m_brightness;
    m_savedContrast = m_contrast;
    m_savedField44 = m_field24;
    m_savedField4D = m_field28;
    m_savedField4E = m_field29;
    g_preferencesPreserved = 1;
}
