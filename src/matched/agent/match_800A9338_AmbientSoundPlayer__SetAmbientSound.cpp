struct ASndP { char p[4]; int* m_snd; void SetAmbientSound(int* s); };
void ASndP::SetAmbientSound(int* s) { m_snd = s; }
