class EResPrefetchFile { char pad[64]; int m_val; public: int Tell() const; };
int EResPrefetchFile::Tell() const { return m_val; }
