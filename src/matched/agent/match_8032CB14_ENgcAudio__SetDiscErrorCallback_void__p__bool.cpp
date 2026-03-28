class ENgcAudio { char pad[60]; int m_val; public: void SetDiscErrorCallback(bool); };
void ENgcAudio::SetDiscErrorCallback(bool val) { m_val = val; }
