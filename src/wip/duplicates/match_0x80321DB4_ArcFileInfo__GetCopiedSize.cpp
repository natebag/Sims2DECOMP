struct ArcFileInfo {
    char _pad[0x0c];
    int m_copiedSize;
    int GetCopiedSize();
};
int ArcFileInfo::GetCopiedSize() { return m_copiedSize; }
