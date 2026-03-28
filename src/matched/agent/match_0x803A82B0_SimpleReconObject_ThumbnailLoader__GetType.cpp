struct SimpleReconObject_ThumbnailLoader {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ThumbnailLoader::GetType() { return m_type; }
