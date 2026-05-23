struct ERSoundTrackData {
    char _p[0x14];
    int *m_instructions;
    int *GetInstruction(unsigned int i);
};
int *ERSoundTrackData::GetInstruction(unsigned int i) { return &m_instructions[i]; }
