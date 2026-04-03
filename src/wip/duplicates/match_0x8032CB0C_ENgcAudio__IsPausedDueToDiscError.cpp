struct ENgcAudio {
    char _pad[0x38];
    int m_val;
    int IsPausedDueToDiscError();
};
int ENgcAudio::IsPausedDueToDiscError() { return m_val; }
