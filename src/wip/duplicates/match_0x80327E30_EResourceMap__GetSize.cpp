struct EResourceMap {
    char _pad[0x04];
    int m_size;
    int GetSize();
};
int EResourceMap::GetSize() { return m_size; }
