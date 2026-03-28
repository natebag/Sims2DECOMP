class EResource { char pad[16]; unsigned int m_sizeField; public: unsigned int GetResSize(); };
unsigned int EResource::GetResSize() { return m_sizeField >> 8; }
