struct PassiveInfluenceTarget {
    char _p[0x08];
    int m_tileVec;
    int *GetTileVector();
};
int *PassiveInfluenceTarget::GetTileVector() { return &m_tileVec; }
