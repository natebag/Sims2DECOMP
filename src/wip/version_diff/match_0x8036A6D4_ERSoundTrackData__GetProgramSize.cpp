struct ERSoundTrackData {
    char _p[0x14];
    int *m_progEnd;
    int *m_progStart;
    int GetProgramSize();
};
int ERSoundTrackData::GetProgramSize() { return m_progStart - m_progEnd; }
