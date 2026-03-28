/* OptionsRecon::RestorePreferences(void) at 0x80058EFC (132B) */

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

    void RestorePreferences(void);
};

void OptionsRecon::RestorePreferences(void) {
    m_musicVol = m_savedMusicVol;
    m_sfxVol = m_savedSfxVol;
    m_voiceVol = m_savedVoiceVol;
    m_screenMode = m_savedScreenMode;
    m_vibration = m_savedVibration;
    m_widescreen = m_savedWidescreen;
    m_subtitles = m_savedSubtitles;
    m_field1F = m_savedField4B;
    m_field20 = m_savedField4C;
    m_brightness = m_savedBrightness;
    m_contrast = m_savedContrast;
    m_field24 = m_savedField44;
    m_field28 = m_savedField4D;
    m_field29 = m_savedField4E;
}
