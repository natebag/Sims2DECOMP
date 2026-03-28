struct ENgcAudio {
    char _pad[0x04];
    float m_musicVolume;
    float GetMusicVolume();
};
float ENgcAudio::GetMusicVolume() { return m_musicVolume; }
