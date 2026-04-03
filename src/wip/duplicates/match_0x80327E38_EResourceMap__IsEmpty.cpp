struct EResourceMap {
    char _p[0x04];
    int m_count;
    int IsEmpty();
};
int EResourceMap::IsEmpty() { return m_count == 0; }
