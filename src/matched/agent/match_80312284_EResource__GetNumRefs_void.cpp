class EResource { char pad[12]; short m_val; public: short GetNumRefs(); };
short EResource::GetNumRefs() { return m_val; }
