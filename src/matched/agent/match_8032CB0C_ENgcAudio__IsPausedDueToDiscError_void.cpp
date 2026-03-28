class ENgcAudio { char pad[56]; int m_val; public: int IsPausedDueToDiscError(); };
int ENgcAudio::IsPausedDueToDiscError() { return m_val; }
