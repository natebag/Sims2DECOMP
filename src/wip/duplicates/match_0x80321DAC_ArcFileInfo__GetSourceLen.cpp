struct ArcFileInfo {
    char _pad[0x08];
    int m_sourceLen;
    int GetSourceLen();
};
int ArcFileInfo::GetSourceLen() { return m_sourceLen; }
