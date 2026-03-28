class ENgcAudio { char pad[8]; float m_val; public: float GetMusicPan(); };
float ENgcAudio::GetMusicPan() { return m_val; }
