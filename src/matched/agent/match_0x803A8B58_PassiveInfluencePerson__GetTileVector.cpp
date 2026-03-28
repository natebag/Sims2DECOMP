struct PassiveInfluencePerson {
    char _p[0x08];
    int m_tileVec;
    int *GetTileVector();
};
int *PassiveInfluencePerson::GetTileVector() { return &m_tileVec; }
