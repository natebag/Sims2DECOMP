class EResourceMap { char pad[4]; int m_numEntries; public: int IsEmpty(); };
int EResourceMap::IsEmpty() { return m_numEntries == 0; }
