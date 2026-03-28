struct ERModel {
    char _pad[0x108];
    int m_numMorphBases;
    int GetNumMorphBases();
};
int ERModel::GetNumMorphBases() { return m_numMorphBases; }
