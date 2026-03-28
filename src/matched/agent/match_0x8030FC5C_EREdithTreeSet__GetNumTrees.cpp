struct EREdithTreeSet {
    char _pad[0x18];
    int m_numTrees;
    int GetNumTrees();
};
int EREdithTreeSet::GetNumTrees() { return m_numTrees; }
