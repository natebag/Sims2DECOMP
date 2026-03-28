class EResource { char pad[8]; unsigned int m_val; public: void SetResId(unsigned int); };
void EResource::SetResId(unsigned int val) { m_val = val; }
