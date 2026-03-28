struct ENgcAudio {
    char _pad[0x08];
    float m_musicPan;
    float GetMusicPan();
};
float ENgcAudio::GetMusicPan() { return m_musicPan; }
