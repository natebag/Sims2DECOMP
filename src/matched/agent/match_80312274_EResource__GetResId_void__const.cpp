class EResource { char pad[8]; int m_val; public: int GetResId() const; };
int EResource::GetResId() const { return m_val; }
