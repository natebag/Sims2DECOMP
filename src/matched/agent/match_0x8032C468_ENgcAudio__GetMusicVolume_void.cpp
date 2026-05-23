// 0x8032C468 ENgcAudio::GetMusicVolume(void) (8 B)
struct ENgcAudio { char _pad[0x4]; float m_field; float GetMusicVolume(); };
float ENgcAudio::GetMusicVolume() { return m_field; }
