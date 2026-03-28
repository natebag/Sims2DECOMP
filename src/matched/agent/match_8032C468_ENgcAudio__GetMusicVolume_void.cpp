class ENgcAudio { char pad[4]; float m_val; public: float GetMusicVolume(); };
float ENgcAudio::GetMusicVolume() { return m_val; }
