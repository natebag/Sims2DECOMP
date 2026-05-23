// 0x800AA9B4 AmbientSoundPlayer::GetAmbientSound(void) (8 B)
struct AmbientSoundPlayer { char _pad[0x4]; unsigned m_ambientSound; unsigned GetAmbientSound(); };
unsigned AmbientSoundPlayer::GetAmbientSound() { return m_ambientSound; }
