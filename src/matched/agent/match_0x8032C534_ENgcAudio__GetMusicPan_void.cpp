// 0x8032C534 ENgcAudio::GetMusicPan(void) (8 B)
struct ENgcAudio { char _pad[0x8]; float m_field; float GetMusicPan(); };
float ENgcAudio::GetMusicPan() { return m_field; }
