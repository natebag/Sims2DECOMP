struct PassiveInfluenceObject {
    char _p[0x08];
    int m_tileVec;
    int *GetTileVector();
};
int *PassiveInfluenceObject::GetTileVector() { return &m_tileVec; }
